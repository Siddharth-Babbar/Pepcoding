#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;
int display(vi &dp)
{
    for (int ele : dp)
    {
        cout << ele << " ";
    }
}
int display2D(vvi &dp)
{
    for (vi e : dp)
    {
        for (int ele : e)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
string Ans = "";
int MCM_01(vi &arr, int si, int ei)
{
    if (si + 1 == ei)
    {
        return 0;
    }
    int minAns = 1e7;
    string Myans = "";
    for (int cut = si + 1; cut < ei; cut++)
    {
        int left = MCM_01(arr, si, cut);
        int right = MCM_01(arr, cut, ei);

        int myCost = left + arr[si] * arr[cut] * arr[ei] + right;
        minAns = min(minAns, myCost);
    }
    return minAns;
}
pair<int, string> MCM_01String(vi &arr, int si, int ei)
{
    if (si + 1 == ei)
    {
        string str = string(1, (char)(si + 'A'));
        pair<int, string> base = {0, str};
        return base;
    }
    pair<int, string> minAns = {1e7, ""};
    for (int cut = si + 1; cut < ei; cut++)
    {
        pair<int, string> left = MCM_01String(arr, si, cut);
        pair<int, string> right = MCM_01String(arr, cut, ei);

        int myCost = left.first + arr[si] * arr[cut] * arr[ei] + right.first;
        if (myCost < minAns.first)
        {
            minAns.first = myCost;
            minAns.second = "(" + left.second + right.second + ")";
        }
    }
    return minAns;
}
int MCM_02(vi &arr, int si, int ei, vvi &dp)
{
    if (si + 1 == ei)
    {
        return 0;
    }
    if (dp[si][ei] != 0)
    {
        return dp[si][ei];
    }
    int minAns = 1e7;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int left = MCM_02(arr, si, cut, dp);
        int right = MCM_02(arr, cut, ei, dp);

        int myCost = left + arr[si] * arr[cut] * arr[ei] + right;
        minAns = min(minAns, myCost);
    }
    dp[si][ei] = minAns;
    return minAns;
}
pair<int, string> MCM_02String(vi &arr, int si, int ei, vector<vector<pair<int, string>>> &dp)
{
    if (si + 1 == ei)
    {
        string str = string(1, (char)(si + 'A'));
        dp[si][ei] = {0, str};
        return dp[si][ei];
    }
    if (dp[si][ei].first != 0)
    {
        return dp[si][ei];
    }
    pair<int, string> minAns = {1e7, ""};
    for (int cut = si + 1; cut < ei; cut++)
    {
        pair<int, string> left = MCM_02String(arr, si, cut, dp);
        pair<int, string> right = MCM_02String(arr, cut, ei, dp);

        int myCost = left.first + arr[si] * arr[cut] * arr[ei] + right.first;
        if (myCost < minAns.first)
        {
            minAns.first = myCost;
            minAns.second = "(" + left.second + right.second + ")";
        }
    }
    dp[si][ei] = minAns;
    return minAns;
}
int MCM_03(vi&arr,vvi & dp)
{
    for(int gap=2;gap<arr.size();gap++)
     {
         for(int si=0,ei=gap;ei<arr.size();si++,ei++)
          {
              int minAns=1e7;
             for(int cut=si+1;cut<ei;cut++)
              {
                  int left=dp[si][cut];
                  int right=dp[cut][ei];

                  int myCost=left + arr[si]*arr[cut]*arr[ei]+ right;
                  minAns=min(minAns,myCost);
              }
             dp[si][ei]=minAns;
          }
     }
    return dp[0][arr.size()-1];
}
int MCM_03String(vi& arr,vvi & dp)
{
    int n=arr.size();
    vector<vector<string>> sdp(n,vector<string>(n,""));
    for(int gap=0;gap<n;gap++)
     {
       for(int si=0,ei=gap;ei<n;si++, ei++)
        {
            if(si+1==ei)
             {
                 sdp[si][ei]=string(1,(char)(si+'A'));
                 continue;
             }
            int minAns=1e7;
            for(int cut=1;cut<ei;cut++)
             {
                 int left=dp[si][cut];
                 int right=dp[cut][ei];

                 int myCost=left + arr[si]*arr[cut]*arr[ei]+ right;

                 if(myCost<minAns)
                  {
                      dp[si][ei]=myCost;
                      minAns=myCost;
                      sdp[si][ei]="("+sdp[si][cut]+sdp[cut][ei]+")";
                  }

             }
        }   
     }
    cout<<sdp[0][n-1]<<":->"<<dp[0][n-1];
    return dp[0][n-1];

}
void set10()
{
    vi arr = {10, 20, 30, 40, 30}; // ans=30000
    // vi arr = {40, 20, 30, 10, 30}; // ans=26000
    // cout << MCM_01(arr, 0, arr.size() - 1) << endl;
    // pair<int,string> ans=MCM_01String(arr,0,arr.size()-1);
    // cout<<ans.second<<":->"<<ans.first<<endl;

    vvi dp(arr.size(), vi(arr.size(), 0));
    // vector<vector<pair<int, string>>> dp(arr.size(), vector<pair<int, string>>(arr.size(), {0, ""}));
    // cout << MCM_02(arr, 0, arr.size() - 1, dp) << endl;
    // pair<int, string> ans = MCM_01String(arr, 0, arr.size() - 1);
    // cout<<ans.second<<":->"<<ans.first<<endl;
    // display2D(dp);

    // cout<<MCM_03(arr,dp)<<endl;
    cout<<MCM_03String(arr,dp)<<endl;
    display2D(dp);
}
int main(int args, char **argv)
{
    set10();
    return 0;
}