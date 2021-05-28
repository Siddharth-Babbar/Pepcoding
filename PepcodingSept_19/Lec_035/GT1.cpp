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
int maximum(Node * node)
{
    int maxi=node->data;
    for(Node* child:node->childs)
     {
         maxi=max(maxi,maximum(child));
     }
    return maxi;
}
int size(Node* node)
{
    int sz=0;
    for(Node* child:node->childs)
     {
         sz+=size(child);
     }
    return sz+1;
}
int height(Node* node)
{
    int ht=-1;
    for(Node* child:node->childs)
     {
         ht=max(ht,height(child));
     }
    return ht+1;
}
bool find(Node* node,int data)
{
    if(node->data==data)
     {
         return true;
     }
    bool res=false;
    for(Node* child:node->childs)
     {
         res=res|| find(child,data);
     } 
    return res;
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

void solve()
{
    vector<int> arr={10,20,50,-1,60,-1,-1,30,70,-1,80,100,-1,110,-1,-1,90,-1,-1,40,-1,-1};
    Node * node=createTree(arr);
    display(node);
    cout<<"Size:"<<size(node)<<endl;
    cout<<"Height:"<<height(node)<<endl;
    cout<<"Find:"<<find(node,110)<<endl;
    cout<<"Maximum:"<<maximum(node)<<endl;
    linearize(node);
    display(node);
}
int main(int args,char** argv)
{
    solve();
    return 0;
}