#include<iostream>
#include<vector>

using namespace std;
void input(vector<int> & arr)
{
    for(int i=0;i<arr.size();i++)
     {
         cin>>arr[i];
     }
}
void dispaly(vector<int> & arr)
{
    for(int i=0;i<arr.size();i++)
     {
         cout<<arr[i];
     }
    cout<<endl;
}
bool q1(vector<int> & arr,int data)
{
    for(int i=0;i<arr.size();i++)
     {
         if (arr[i]==data)
          {
              return true;
          }
     }
    return false;
}
int maximum(vector<int> & arr)
{
    int m=arr[0];
        for(int i=1;i<arr.size();i++)
     {
        if(m<=arr[i])
         {
             m=arr[i];
         }
     }
    return m;
}
int minimum(vector<int> & arr)
{
    int m=arr[0];
    for(int i=1;i<arr.size();i++)
     {
         if(m>=arr[i])
          {
              m=arr[i];
          }
     }
    return m;
}
int main(int args,char** argv)
{
    int n,n1;
    cout<<"Enter  the size of array"<<endl;
    cin>>n;
    vector<int> arr(n,0);
    input(arr);
    cout<<"Enter  the num"<<endl;
    cin>>n1;
    cout<<q1(arr,n1)<<endl;
    cout<<maximum(arr)<<endl;
    cout<<minimum(arr);

    return 0;
}