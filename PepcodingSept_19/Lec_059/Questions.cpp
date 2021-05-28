#include<iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//leetcode 141===================================================
bool hasCycle(ListNode* head)
{
  if(head == nullptr || head->next == nullptr)
   {
       return false;
   }
  ListNode* slow=head;
  ListNode* fast=head;

  while(fast!=nullptr && fast->next!=nullptr)
   {
       slow=slow->next;
       fast=fast->next->next;

       if(slow == fast)
        {
            break;
        }
   }

   return slow == fast;
}

//leetcode 142
ListNode* detectCycle(ListNode* head)
{
  if(head == nullptr || head->next == nullptr)
   {
       return nullptr;
   }   
   ListNode* slow=head;
   ListNode* fast=head;

   while(fast!=nullptr && fast->next!=nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;

        if(slow == fast)
         {
             break;
         }
    }
   
   if(slow == fast)
    {
        slow=head;
        while(slow !=fast)
         {
             slow=slow->next;
             fast=fast->next;
         }
        return slow;
    }

    return nullptr;

}

//leetcode 160=================================================
ListNode* getIntersectionNode(ListNode* headA,ListNode*  headB)
{
    if(headA == nullptr || headB == nullptr)
     {
         return nullptr;
     }
    if(headA->next == nullptr && headB->next == nullptr && headA->val == headB->val)
     {
         return headA;
     }
    
    ListNode* tail=nullptr;
    ListNode* curr=headA;

    while(curr!=nullptr)
     {
        tail=curr;
        curr=curr->next;
     }  

    tail->next=headB;

    ListNode* slow=headA;
    ListNode* fast=headA;

    while(fast != nullptr && fast->next != nullptr)
     {
         slow=slow->next;
         fast=fast->next->next;

         if(slow == fast)
          {
              break;
          }
     }
    
    if(slow == fast)
     {
         slow=headA;

         while(slow != fast)
          {
              slow=slow->next;
              fast=fast->next;
          }

        tail->next=nullptr;
        return slow;
     }

    tail->next=nullptr;
    return nullptr;
}

// leetcode 21=======================================================
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(l1 == nullptr)
     {
         return l2;
     }
    if(l2 == nullptr)
     {
         return l1;
     }

    ListNode* head=new ListNode(-1);
    ListNode* curr=head;

    while(l1 != nullptr && l2 != nullptr)
     {
        if(l1->val <= l2->val)
         {
             curr->next=l1;
             l1=l1->next;
         }
        else
         {
             curr->next=l2;
             l2=l2->next;
         }
        curr=curr->next;        
     }
    
    if(l1 != nullptr)
     {
         curr->next=l1;
     }
    else
     {
         curr->next=l2;
     }

    return head->next;
}

// leetcode 148
ListNode* middleNodeByIndex(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr)
     {
         slow=slow->next;
         fast=fast->next->next;

         if(slow == fast)
          {
              break;
          }
     }  

    return slow;
}
ListNode* sortList(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
     {
         return head;
     }
    
    ListNode* mid=middleNodeByIndex(head);
    ListNode* nhead=mid->next;
    mid->next=nullptr;

    ListNode* a = sortList(head);
    ListNode* b = sortList(nhead);

    return mergeTwoLists(a,b); 
}