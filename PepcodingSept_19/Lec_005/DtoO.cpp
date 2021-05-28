#include<iostream>

using namespace std;
int DtoO(int n)
{
    int res=0;
    int rem=0;
    int pow=1;
    while(n!=0)
     {
       rem=n%8;
       n/=8;
       res=rem*pow + res;
       pow*=10;
     }
     return res;
}
int main(int args,char** argv)
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<DtoO(n);
    return 0;
}