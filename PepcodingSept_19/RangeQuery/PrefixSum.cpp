#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;
vector<int> prefixSum;
int Query_1(int l,int r)// O(N)
{
  int sum=0;
  for(int i =l;i<=r;i++)
   {
     sum+=arr[i];
   }
  return sum;
}
void Update_1(int idx, int data)// O(1)
{
  arr[idx]=data;
}
int Query_2(int l, int r)//O(1)
{
  if(l == 0)
   {
     return prefixSum[r];
   }
  return prefixSum[r] - prefixSum[l-1];
}
void Update_2(int idx, int data)//O(N)
{
  int delta = data - arr[idx],arrSize= arr.size();
  for(int i=idx;i<arrSize;i++)
   {
     prefixSum[i]+=delta;
   }
  arr[idx]=data;
}
void solve()
{
  int n=0,sum=0;
  cin>>n;
  arr.resize(n,0);
  prefixSum.resize(n,0);
  for(int i=0;i<n;i++)
   {
     cin>>arr[i];
     sum+=arr[i];
     prefixSum[i]=sum;
   }
}
int main(int args,char** argv)
{
  solve();
  int t = 0, c = 0, l = 0, r =0, idx = 0, data = 0;
  cin>>t;
  while(t-->0)
   {
     cin>>c;
     if(c)
      {
        cin>>l>>r;
        // cout<<Query_1(l,r)<<endl;
        cout<<Query_2(l,r)<<endl;
      }
     else
      {
        cin>>idx>>data;
        // Update_1(idx,data);
        Update_2(idx,data);

      }   
   }
  return 0;
}