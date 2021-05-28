#include<iostream>

using namespace std;
int Facto(int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
     {
         ans*=i;
     }
     return ans;
}
int main(int args,char** argv)
{
    int n;
    cout<<"Enter n for factorial:"<<endl;
    cin>>n;
    cout<<"The Factorial is:"<<Facto(n);
    return 0;
}