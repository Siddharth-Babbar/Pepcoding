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
int water(vector<int> & arr)
{
    int max_=0;
    int i=0;
    int j=arr.size()-1;
    while(i<j)
     {
         if(arr[i]<=arr[j])
          {
              max_=max(max_,arr[i]*(j-i));
              i++;
          }
        else
         {
             max_=max(max_,arr[j]*(j-i));
             j--;
         }
     }
    return max_;
}
int main(int args,char** argv)
{
  int n;
  cout<<"Enter the size of tank:"<<endl;
  cin>>n;
  vector<int> arr(n,0);
  input(arr);
  cout<<"The maximum water stored is :";
  cout<<water(arr);
  return 0;
}