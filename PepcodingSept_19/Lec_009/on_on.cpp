#include<iostream>

using namespace std;
int main(int args,char** argv)
{
    int a;
    cin>>a;
    int k;
    cin>>k;
    int mask=(1<<k);
    a|=mask;
    cout<<a;
    return 0;
}
