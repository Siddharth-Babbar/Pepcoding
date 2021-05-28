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
 