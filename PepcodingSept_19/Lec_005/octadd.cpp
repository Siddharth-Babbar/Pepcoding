#include<iostream>

using namespace std;
int octadd(int num1,int num2)
{
    int res=0;
    int rem=0;
    int pow=1;
    int carr=0;
    while(num1!=0||num2!=0||carr!=0)
     {
         rem=num1%10+ num2%10 + carr;
         num1/=10;
         num2/=10;
         carr=rem/8;
         rem%=8;
         res+=rem*pow;
         pow*=10;
     }
     return res;
}
int main(int args,char** argv)
{
    int num1,num2;
    cout<<"Enter the two numbers : ";
    cin>>num1>>num2;
    cout<<"Result: "<<octadd(num1,num2);
    return 0;
}