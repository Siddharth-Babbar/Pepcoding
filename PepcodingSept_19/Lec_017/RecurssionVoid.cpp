#include<iostream>
#include<vector>
#include<string>

using namespace std;
int PermuInfi(vector<int> &arr,int target,string ans)
{
    if(target==0)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    for(int i=0;i<arr.size();i++)
     {
         if(target-arr[i]>=0)
          {
              count+=PermuInfi(arr,target-arr[i],ans+to_string(arr[i]));
          }
     }
    return count;
}
int CombiInfi(vector<int> &arr,int idx,int target,string ans)
{
    if(target==0)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    for(int i=idx;i<arr.size();i++)
     {
       if(target-arr[i]>=0)
        {
            count+=CombiInfi(arr,i,target-arr[i],ans+to_string(arr[i]));
        }
     }
    return count;
}

int CombiWithoutRepetition(vector<int> & arr,int idx,int target,string ans)
{
    if(target==0)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    for(int i=idx;i<arr.size();i++)
     {
         if(target-arr[i]>=0)
          {
              count+=CombiWithoutRepetition(arr,i+1,target-arr[i],ans+to_string(arr[i]));
          }
    
     }
    return count;
}
int PermuWithoutRepetition(vector<int> & arr,vector<bool> & vis,int target,string ans)
{
    if(target==0)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    for(int i=0;i<arr.size();i++)
     {
         if(target-arr[i]>=0 && !vis[i])
          {
              vis[i]=true;
              count+=PermuWithoutRepetition(arr,vis,target-arr[i],ans+to_string(arr[i]));
              vis[i]=false;
          }
        
     }
    return count;
}
int PermiInfisubseq(vector<int> &arr,int idx,int target,string ans)
{
    if(target==0|| idx==arr.size())
     {
         if(target==0)
         {
          cout<<ans<<endl;
          return 1;
         }
         else
         {
             return 0;
         }
         
     }
    int count=0;
    if(target-arr[idx]>=0)
     {
         count+=PermiInfisubseq(arr,0,target-arr[idx],ans+to_string(arr[idx]));
     }
    count+=PermiInfisubseq(arr,idx+1,target,ans);
    return count;
}
int CombiInfisubseq(vector<int> &arr,int idx,int target,string ans)
{
    if(target==0|| idx==arr.size())
     {
         if(target==0)
         {
          cout<<ans<<endl;
          return 1;
         }
         else
         {
             return 0;
         }
         
     }
    int count=0;
    if(target-arr[idx]>=0)
     {
         count+=CombiInfisubseq(arr,idx,target-arr[idx],ans+to_string(arr[idx]));
     }
    count+=CombiInfisubseq(arr,idx+1,target,ans);
    return count;
}
int Permusinglesubseq(vector<int> &arr,int idx,vector<bool> &vis,int target,string ans)
{
    if(target==0|| idx==arr.size())
     {
         if(target==0)
         {
          cout<<ans<<endl;
          return 1;
         }
         else
         {
             return 0;
         }
         
     }
    int count=0;
    if(target-arr[idx]>=0 && !vis[idx])
     {
         vis[idx]=true;
         count+=Permusinglesubseq(arr,0,vis,target-arr[idx],ans+to_string(arr[idx]));
         vis[idx]=false;
     }
    count+=Permusinglesubseq(arr,idx+1,vis,target,ans);
    return count;
}
int Combisinglesubseq(vector<int> &arr,int idx,int target,string ans)
{
    if(target==0|| idx==arr.size())
     {
         if(target==0)
         {
          cout<<ans<<endl;
          return 1;
         }
         else
         {
             return 0;
         }
         
     }
    int count=0;
    if(target-arr[idx]>=0)
     {
         count+=Combisinglesubseq(arr,idx+1,target-arr[idx],ans+to_string(arr[idx]));
     }
    count+=Combisinglesubseq(arr,idx+1,target,ans);
    return count;
}

void permucombi()
{
   vector<int> arr={2,3,5,7};
   vector<bool> vis(arr.size(),false);
   int target=10;
   vector<bool> box(5, false);
 cout<<PermuInfi(arr,target,"");
//  cout<<CombiInfi(arr,0,target,"");
//  cout<<CombiWithoutRepetition(arr,0,target,"");
//  cout<<PermuWithoutRepetition(arr,vis,target,"");
//  cout<<PermiInfisubseq(arr,0,target,"");
//  cout<<CombiInfisubseq(arr,0,target,"");
//  cout<<Permusinglesubseq(arr,0,vis,target,"");
//  cout<<Combisinglesubseq(arr,0,target,"");
    
}
void solve()
{
  permucombi();
}
int main(int args,char** argv)
{
    solve();
    return 0;
}