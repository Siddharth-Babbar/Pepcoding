#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int maximum(vector<int> & arr,int vidx)
{
    if(vidx==arr.size())
    return INT_MIN;
    int ans=maximum(arr,vidx+1);
    return max(arr[vidx],ans);

}
 
int main (int args,char** argv)
{
  vector<int> arr={20,64,50,30,-10,3,38,10};
  cout<< maximum(arr,0);
  return 0;

}