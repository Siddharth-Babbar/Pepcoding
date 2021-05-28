#include<iostream>

using namespace std;
void evenodd(int n)
{
    if(n==0)
     {
         cout<<n<<endl;
         return;

     }
    if(n%2==0)
    cout<<n<<endl;
    evenodd(n-1);
    if(n%2!=0)
    cout<<n<<endl;
}
int main(int args,char** argv)
{
  evenodd(10);
  return 0;
}