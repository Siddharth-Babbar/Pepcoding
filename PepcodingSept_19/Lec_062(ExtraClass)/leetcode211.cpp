#include<iostream>
#include<vector>

using namespace std;

class Node
{
    public:
    int WordEnd=0;
    vector<Node*> childs;

    Node()
    {
        this->WordEnd=0;
        this->childs.assign(26,nullptr);
    }
};

Node* root=nullptr;
WordDictionary()
{
    root=new Node();
}
void addWord(string word)
{
    Node* curr =root;
    int n=word.length();
    for(int i=0;i<n;i++)
     {
         int idx=word[i]-'a';
         if(curr->childs[i]==nullptr)
          {
              curr->childs[i]=new Node();
          }
         curr=curr->childs[i];
     }
    curr->WordEnd++;
}
bool search_(Node* node,int si,string word)
{
    if(si == word.length())
     {
         return node->WordEnd!=0;
     }
    bool res=false;
    if(word[si]='.')
     {
         for(int i=0;i<26;i++)
          {
              if(node->childs[i]!= nullptr)
               {
                  res=res||search_(node->childs[i],si+1,word);
               }               
          }
     }
    else
     {
        int idx=word[si]-'a';
        if(node->childs[idx]!=nullptr)
         {
            res=res||search_(node->childs[idx],si+1,word);
         }
     }
    return res;
}
bool search(string word)
{
    return search_(root,0,word);
}