#include<iostream>

using namespace std;
void fullDiamond(int rows)
{
    int nst=1;
    int nsp=rows-1;
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
        if(i<=rows/2)
         {
             nsp--;
             nst+=2;
             cout<<endl;
         }
        else
         {
           nsp++;
           nst-=2;
           cout<<endl;
         } 

     }
}
int main(int args,char** argv)
{
    int rows;
    cout<<"Enter number of rows:"<<endl;
    cin>>rows;
    fullDiamond(rows);
    return 0;
}