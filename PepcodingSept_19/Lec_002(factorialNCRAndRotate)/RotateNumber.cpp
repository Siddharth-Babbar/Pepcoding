#include<iostream>
#include<math.h>

using namespace std;
int digit(int n)
{
    int i=1;
    int a=n;
    while((a/10)!=0)
     {
       i++;
       a=a/10;
     }
     return i;
}
int rotate(int n,int r)
{
    int b,c;
    c=digit(n);
    b=r%c;
    b=(b<0)?(b+c):b;
    int multip=1;
    int divd=1;
    for(int i=1;i<=c;i++)
     {
       if(i<=r)
       multip*=10;
       else 
       divd*=10;
     }  
     
    // multip=pow(10,r)+1;
    // divd=pow(10,(c-r))+1;
    // cout<<multip<<" "<<divd<<" ";
    int fdigit=n%divd;
    int sdigit=n/divd;
     

    int num=fdigit*multip+sdigit;
    return num;
   
}
int main(int args,char** argv)
{
    int n,r;
    cout<<"Enter the number :";
    cin>>n;   
    cout<<"Enter r:";
    cin>>r;
    cout<<endl<<"Number after rotation:";
    cout<<rotate(n,r);
   
    return 0;
}