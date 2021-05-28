#include<iostream>
#include<vector>

using namespace std;
void display(vector<int> & arr,int i)
{
  if(i==arr.size())
  return;
  cout<<arr[i]<<" ";
  display(arr,i+1);
}
int main(int args,char** argv)
{
    vector<int> arr={10,20,50,30,-10,3,38,64};
    display(arr,0);
    return 0;
}
