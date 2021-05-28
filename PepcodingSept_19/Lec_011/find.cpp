#include<iostream>
#include<vector>
#include<climits>

using namespace std;
bool find(vector<int> & arr,int vidx,int data)
{
    if(vidx==arr.size())
    return false;
    if(arr[vidx]==data)
    return true;
    return find(arr,vidx+1,data);
}
int main (int args,char** argv)
{
  vector<int> arr={20,64,50,30,-10,3,38,10};
  cout<< find(arr,0,200);
  return 0;

}