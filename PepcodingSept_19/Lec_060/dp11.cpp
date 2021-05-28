#include<iostream>
#include<vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;
void display2D(vvi & dp)
{
    for(vi e: dp)
     {
         for(int ele : e)
          {
             cout<<ele<<" ";
          }
          cout<<endl;
     }
}
//Leetcode 312
int burstBallon_01(vector<int> & arr,int si,int ei)
{
    int l = ( si-1 == -1 ) ? 1 : arr[si-1];
    int r = ( ei+1 == arr.size() ) ? 1 : arr[ei+1];

    int minAns=0;
    for(int cut=si;cut<=ei;cut++)
     {
         int left = ( si == cut ) ? 0 : burstBallon_01(arr,si,cut-1);
         int right = ( ei == cut ) ? 0 : burstBallon_01(arr,cut+1,ei);

         int myCost = left + l*arr[cut]*r + right;

         if(myCost > minAns)
          {
              minAns = myCost;
          }
     }
    return minAns;
}
int burstBallon_02(vector<int> & arr,int si,int ei,vector<vector<int>> & dp)
{
    if( dp[si][ei] !=0)
     {
         return dp[si][ei];
     }
    int l = ( si -1 == -1) ? 1 : arr[si - 1];
    int r = ( ei + 1 == arr.size() ) ? 1 : arr[ei + 1];

    int minAns=0;   
    for(int cut =si ; cut <= ei ; cut++)
     {
         int left = (si == cut) ? 0 : burstBallon_02(arr,si,cut - 1,dp);
         int right = (ei == cut) ? 0 : burstBallon_02(arr,cut + 1,ei,dp);

         int myCost= left + l*arr[cut]*r + right;

         if(minAns < myCost)
          {
              minAns = myCost;
          }  
     }
    
    dp[si][ei] = minAns;
    return dp[si][ei];

}
int burstBallon_03(vector<int> & arr,vector<vector<int>> & dp)
{
    for(int gap =0 ;gap < arr.size();gap ++)
     {
         for(int si = 0, ei = gap;ei <arr.size() ; si++, ei++)
          {
              int l = (si - 1 == -1) ? 1 : arr[si - 1];
              int r = (ei + 1 == arr.size()) ? 1 : arr[ei +1];
              
              int minAns = 0;
              for(int cut = si;cut <= ei; cut++)
               {
                   int left = (si == cut ) ? 0 : dp[si][cut-1];
                   int right = (ei == cut) ? 0 : dp[cut+1][ei];

                   int myCost = left + l*arr[cut]*r + right;

                   if(myCost > minAns)
                    {
                        minAns=myCost;
                    } 
               }
              dp[si][ei] = minAns;
          }
     }
    
    return dp[0][arr.size()-1];
}
void set11()
{
    vi arr={3 , 1 , 5 , 8};
    vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),0));

    // cout<< burstBallon_01(arr,0,arr.size()-1)<<endl;
    // cout<< burstBallon_02(arr,0,arr.size()-1,dp)<<endl;
    cout<< burstBallon_03(arr,dp)<<endl;

    display2D(dp);
}
int main(int args,char** argv)
{
    set11();
    return 0;
}