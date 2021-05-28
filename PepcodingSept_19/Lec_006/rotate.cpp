#include<iostream>
#include<vector>

using namespace std;
void input (vector<int> & arr)
{
    for(int i=0;i<arr.size();i++)
     {
         cin>>arr[i];
     }
}
void display(vector<int> & arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i];
    }
    cout<<endl;

}
void reverse(vector<int> & arr,int l,int u)
{
    for(int i=l,k=u;i<=k;i++,k--)
    {
        int temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
    }
}
void rotate(vector<int> & arr,int r)
{
    int n=arr.size();
    r%=n;
    if(r<0)
    {
     r+=n;
     cout<<r<<endl;
    }
  
  
  reverse(arr,0,r-1);
  reverse(arr,r,arr.size()-1);
  reverse(arr,0,arr.size()-1);
}
int main(int args,char** argv)
{
    int n,r;
    cout<<"Enter the number of terms"<<endl;
    cin>>n;
    vector<int> arr(n,0);
    input(arr);
    cout<<"Enter r"<<endl;
    cin>>r;
    rotate(arr,r);
    display(arr);
    return 0;
}