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
void nc_r()
{
    int n,r;
    cout<<"Enter N:";
    cin>>n;
    cout<<endl;
    cout<<"Enter R:";
    cin>>r;
    cout<<endl;
    cout<<(Facto(n))/(Facto(n-r)*Facto(r));
}
int main(int args,char** argv)
{
    nc_r();
    return 0;
}