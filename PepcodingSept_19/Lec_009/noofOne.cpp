#include<iostream>

using namespace std;
void noOfSetBits_1(int a)
{
    int count=0;
    for(int i=0;i<32;i++)
     {
        int mask=(1<<i);
        if((a&mask)!=0)
        count++;
        
     }
    cout<<count;
}
void noOfSetBits_1_2(int a)
{
    int count=0;
    while(a!=0 && count<32)
     {
       if((a&1)!=0)
       count++;
       a>>=1;
     }
    cout<<count;
    
}
int main(int args,char** argv)
{
    int a;
    cin>>a;
    noOfSetBits_1(a);
    noOfSetBits_1_2(a);
    return 0;
}