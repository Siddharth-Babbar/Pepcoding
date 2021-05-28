#include<iostream>

using namespace std;
void NumberPrint(int n)
{
    if(n==0)
    {
        cout<<"BASE :"<<n<<endl;
        return;
    }
    cout<<"HI :"<<n<<endl;
    NumberPrint(n-1);
    cout<<"BYE :"<<n<<endl;
}
int main(int args,char** argv)
{
   NumberPrint(10);
   return 0;
}