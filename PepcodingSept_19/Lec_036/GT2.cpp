#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Node
{
    public:
    int data=0;
    vector<Node*> childs;
    Node()
     {

     }
    Node(int data)
     {
        this->data=data;
     }
};
Node* createTree(vector<int> &arr)
{
    stack<Node*> st;
    for(int i=0;i<arr.size()-1;i++)
     {
         if(arr[i]!=-1)
          {
              Node* node=new Node(arr[i]);
              st.push(node);
          }
         else
          {
             Node* node=st.top();
             st.pop();
             st.top()->childs.push_back(node);
          }
         
     }
    return st.top(); 
}
void display(Node* node)
{
    cout<<node->data<<":->";
    for(Node* child:node->childs)
     {
         cout<<child->data<<", ";
     }
    cout<<endl;
    for(Node* child:node->childs)
     {
         display(child);
     }


}
Node* getTail(Node* node)
{
    if(node->childs.size()==0)
     {
        return node;
     }
    return getTail(node->childs[0]);
}
void linearize(Node * node )
{
    for(Node* child:node->childs)
     {
         linearize(child);
     }
    for(int i=node->childs.size()-2;i>=0;i--)
     {
         Node* tail=getTail(node->childs[i]);
         tail->childs.push_back(node->childs[i+1]);

         node->childs.pop_back();
     }
}
Node* linearize_02(Node* node)
{
    if(node->childs.size()==0)
     {
         return node;
     }
    Node* myTail=linearize_02(node->childs.back());
    for(int i=node->childs.size()-2;i>=0;i--)
     {
         Node* tail=linearize_02(node->childs[i]);
         tail->childs.push_back(node->childs[i+1]);
         node->childs.pop_back();
     }
    return myTail;
}
bool isSysmetric (Node* node1,Node* node2)
{
    if(node1->childs.size()!=node2->childs.size())
     {
         return false;
     }
    for(int i=0,j=node1->childs.size()-1;i<=j;i++,j--)
     {
         Node* child1=node1->childs[i];
         Node* child2=node2->childs[j];
         
         if(!isSysmetric(child1,child2))
          {
             return false;
          }
     }
     return true;
}
bool isMirror (Node* node1,Node* node2)
{
    if(node1->childs.size()!=node2->childs.size() || node1->data!=node2->data)
     {
         return false;
     }
    for(int i=0,j=node1->childs.size()-1;i<=j;i++,j--)
     {
         Node* child1=node1->childs[i];
         Node* child2=node2->childs[j];
         
         if(!isSysmetric(child1,child2))
          {
             return false;
          }
     }
     return true;
}
int removeLeaf_01(Node* node)
{
    if(node->childs.size()==0)
     {
         return 1;
     }
    int res=0;
    for(int i=0;i<node->childs.size();)
     {
        res=0;
        res=removeLeaf_01(node->childs[i]);
        if(res)
         {
             node->childs.erase(node->childs.begin()+i);
         }
        else
         {
             i++;
         }
        
        
     }
    return 0;
}
void removeLeaf_02(Node* node)
{
    vector<Node*> nchilds;
    for(Node* child:node->childs) 
     {
         if(child->childs.size()!=0)
          {
              nchilds.push_back(child);
          }
     } 
    node->childs=nchilds;
    for(Node * child:node->childs)
     {
         removeLeaf_02(child);
     }
}
void spiralPrint(Node* node,int level)
{
    stack<pair<Node *,int>> st1;
    stack<pair<Node *,int>> st2;
    st1.push({node,0});
    while(st1.size()!=0 || st2.size()!=0)
     {
         Node* rnode=st1.top().first;
         int level=st1.top().second;
         st1.pop();
         cout<<rnode->data<<" ";
         if((level&1)==0)
          {
              for(Node * child:rnode->childs)
               {
                   st2.push({child,level+1});
               }
          }
         else
          {
              for(int i=rnode->childs.size()-1;i>=0;i--)
               {
                   st2.push({rnode->childs[i],level+1});
               }
          }
         
         if(st1.size()==0)
          {
              cout<<endl;
              swap(st1,st2);
          }
     }
}
void solve()
{
    vector<int> arr={10,20,50,-1,60,-1,-1,30,70,-1,80,100,-1,110,-1,-1,90,-1,-1,40,-1,-1};
    Node * node=createTree(arr);
    // display(node);
    //linearize(node);
    // cout<<isSysmetric(node,node)<<endl;
    // Node* tail=linearize_02(node);
    // cout<<endl;
    // display(node);
    // cout<<isSysmetric(node,node)<<endl;
    // int ans=removeLeaf_01(node);
    // removeLeaf_02(node);
    // cout<<endl;
    // display(node);
    spiralPrint(node,0);
}
int main(int args,char** argv)
{
    solve();
    return 0;
}