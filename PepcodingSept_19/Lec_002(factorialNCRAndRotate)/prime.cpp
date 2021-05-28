#include<iostream>

using namespace std;

bool isPrime(int n)
{
  for(int i=2;i*i<=n;i++)
   {
     if((n%i)==0)
      {
        return false;
      }
   }
  return true;
}
int main(int args,char** argv)
{
  int n=0;
  cout<<"Enter the number:";
  cin>>n;
  if(isPrime(n))
   {
     cout<<"The number is prime.";
   }
  else 
   {
     cout<<"The number is composite.";
   }
  return 0;
}