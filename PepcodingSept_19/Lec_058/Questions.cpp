#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* middleNodeBYINDEX(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr)
     {
         slow=slow->next;
         fast=fast->next->next;
     }
    
    return slow;
}

//leetcode876================================

ListNode* middleNodeBYSize(ListNode* head)
{
    ListNode* slow=head;
    ListNode* fast=head;

    while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr)
     {
         slow=slow->next;
         fast=fast->next->next;
     }
    
    return fast->next==nullptr?slow:slow->next;
}

//leetcode206===========================================================================

ListNode* reverse(ListNode* head)
{
    ListNode* prev=nullptr;
    ListNode* curr=head;
    ListNode* forw=nullptr;

    while(curr!=nullptr)
     {
         forw=curr->next;

         curr->next=prev;

         prev=curr;
         curr=forw;
     }
    return prev;
}

//leetcode 234

bool isPalindrome(ListNode* head)
{
    if(head==nullptr || head->next==nullptr)
     {
         return true;
     }
    ListNode* mid=middleNodeBYINDEX(head);
    ListNode* nhead=mid->next;
    mid->next=nullptr;

    nhead=reverse(nhead);

    ListNode* curr1=head;
    ListNode* curr2=nhead;

    while(curr1!=nullptr || curr2!=nullptr)
     {
         if(curr1->val!=curr2->val)
          {
              return false;
          }
         curr1=curr1->next;
         curr2=curr2->next;
     }
    return true;
    
}