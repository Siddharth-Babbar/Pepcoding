#include<iostream>

using namespace std;
int main(int argv, char** args)
{    
    cout<<"Even number :";
    for(int i=1;i<=50;i++)
     {
         cout<<" "<<2*i;
     }
     cout<<endl<<"Odd number:";
     for(int i=0;i<=50;i++)
      {
          cout<<" "<<(2*i +1);
      }
     return 0; 
}