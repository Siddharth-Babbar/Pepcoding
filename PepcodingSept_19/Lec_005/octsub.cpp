#include<iostream>

using namespace std;
int octsub(int num1,int num2)
{
    bool isTrue=false;
    int temp;
    if(num1<num2)
    {
        isTrue=true;
        temp=num1;
        num1=num2;
        num2=temp;
    }
    int res=0;
    int rem=0;
    int borr=0;
    int pow=1;
    while(num1!=0)
     {
       rem=num1%10-num2%10 + borr;
       num1/=10;
       num2/=10;
       if(rem<0)
        {
           rem+=8;
           borr=-1;
        }
       else 
        {
            borr=0;
        }
       res+=rem*pow;
       pow*=10;
     }
    if(isTrue==true)
     {
         res*=-1;
     }
     return res;
}
int main(int args,char** argv)
{
    int num1,num2;
    cout<<"Enter the two numbers : ";
    cin>>num1>>num2;
    cout<<"Result : "<<octsub(num1,num2);
    
    return 0;


    
}