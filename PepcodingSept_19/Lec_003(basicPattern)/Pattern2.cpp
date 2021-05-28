#include<iostream>

using namespace std;
void mirrorPattern(int rows)
{
    int nst=1;
    int nsp=0;
    for(int i=1;i<=rows;i++)
    {
        for(int csp=1;csp<=nsp;csp++)
         {
             cout<<" ";
         }
        for(int cst=1;cst<=nst;cst++)
         {
             cout<<"*";
         }
         nst++;
         nsp=0;
         cout<<endl;
    }
}
int main(int args,char** argv)
{
    int rows;
    cout<<"Enter number of rows:"<<endl;
    cin>>rows;
    mirrorPattern(rows);
    return 0;
}