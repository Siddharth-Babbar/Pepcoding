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
vector<int> Inverse(vector<int> & arr,int idx)
{
    if(idx==arr.size())
    {
        vector<int> base(arr.size(),0);
        return base;
    }
    int val=arr[idx];
    vector<int> myans;
    myans=Inverse(arr,idx+1);
    myans[val]=idx;
    return myans;
}
int main(int args,char** argv)
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    input(arr);
    int i;
    cin>>i;
    vector<int> ans=Inverse(arr,0);
    for(int ele:ans)
    {
        cout<<ele<<" ";
    }
    cout<<endl<<ans[i];
    return 0;
}