#include<iostream>
#include<vector>

using namespace std;
void input(vector<int> &arr)
{
    for(int i=0;i<arr.size();i++)
     {
         cin>>arr[i];
     }
}
void display(vector<int> &arr)
{
    for(int i=0;i<arr.size();i++)
     {
         cout<<arr[i]<<endl;
     }
} 

int main(int args,char** argv)
{
    int n;
    cout<<"Enter the size "<<endl;
    cin>>n;
    vector<int> arr(n,0);
    input(arr);
    display(arr);
    return 0;
}