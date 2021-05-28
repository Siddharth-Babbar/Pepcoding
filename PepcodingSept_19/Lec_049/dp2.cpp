#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;
void display(vi &dp)
{
    for (int ele : dp)
    {
        cout << ele << " ";
    }
}
// int boardPath_01(int n)
// {
//     if(n==0)
//      {
//          return 1;
//      }
//     int count=0;
//     for(int i=1;i<=6;i++)
//      {
//          if((n-i)>=0)
//           {
//               count+=boardPath_01(n-i);
//           }
//      }
//     return count;
// }
// int boardPath_02(int n,vi& dp)
// {
//     if(n==0)
//      {
//          dp[n]=1;
//          return 1;
//      }
//     int count=0;
//     if(dp[n]!=0)
//      {
//          return dp[n];
//      }
//     for(int i=1;i<=6;i++)
//      {
//          if((n-i)>=0)
//           {
//               count+=boardPath_02(n-i,dp);
//           }
//      }
//     dp[n]=count;
//     return count;
// }
// int climb02(int n, vector<int> &dp)
// {
//     for (int i = 0; i <= n; i++)
//     {
//         if (i == 0)
//         {
//             dp[i] = 1;
//             continue;
//         }
//         int count = 0;

//         if ((i - 1) >= 0)
//         {
//             count += dp[i - 1];
//         }
//         if ((i - 2) >= 0)
//         {
//             count += dp[i - 2];
//         }
//         dp[i] = count;
//     }
//     return dp[n];
// }
int boardPath_01(int st, int end)
{
    if (st == end)
    {
        return 1;
    }
    int count = 0;
    for (int dice = 1; dice <= 6 && st + dice <= end; dice++)
    {
        count += boardPath_01(st + dice, end);
    }
    return count;
}
int boardPath_02(int st, int end, vi &dp)
{
    if (st == end)
    {
        dp[st] = 1;
        return 1;
    }
    int count = 0;
    if (dp[st] != 0)
    {
        return dp[st];
    }
    for (int dice = 1; dice <= 6 && st + dice <= end; dice++)
    {
        count += boardPath_02(st + dice, end, dp);
    }
    dp[st] = count;
    return count;
}
int boardPath_03(int stp, int end, vi &dp)
{
    for (int st = end; st >= stp; st--)
    {
        if (st == end)
        {
            dp[st] = 1;
            continue;
        }
        int count = 0;
        for (int dice = 1; dice <= 6 && st + dice <= end; dice++)
        {
            count += dp[st + dice];
        }
        dp[st] = count;
    }
    return dp[0];
}
int boardPath_01_giveOutcomes(int st, int end, vi &Outcomes)
{
    if (st == end)
    {
        return 1;
    }
    int count = 0;
    // for(int i=0;i<Outcomes.size() && st+Outcomes[i]<=end;i++) For sorted Outcomes
    for (int i = 0; i < Outcomes.size(); i++)
    {
        if (st + Outcomes[i] <= end)
        {
            count += boardPath_01_giveOutcomes(st + Outcomes[i], end, Outcomes);
        }
    }
    return count;
}
int boardPath_02_giveOutcomes(int st, int end, vi &Outcomes, vi &dp)
{
    if (st == end)
    {
        dp[st] = 1;
        return 1;
    }
    int count = 0;
    if (dp[st] != 0)
    {
        return dp[st];
    }
    // for(int i=0;i<Outcomes.size() && st+Outcomes[i]<=end;i++) For sorted Outcomes
    for (int i = 0; i < Outcomes.size(); i++)
    {
        if (st + Outcomes[i] <= end)
        {
            count += boardPath_02_giveOutcomes(st + Outcomes[i], end, Outcomes, dp);
        }
    }
    dp[st] = count;
    return count;
}
int boardPath_03_giveOutcomes(int stp, int end, vi &Outcomes, vi &dp)
{
    for (int st = end; st >= end; st--)
    {
        if (st == end)
        {
            dp[st] = 1;
            continue;
        }
        int count = 0;
        // for(int i=0;i<Outcomes.size() && st+Outcomes[i]<=end;i++) For sorted Outcomes
        for (int i = 0; i < Outcomes.size(); i++)
        {
            if (st + Outcomes[i] <= end)
            {
                count += dp[st + Outcomes[i]];
            }
        }
        dp[st] = count;
    }
    return dp[0];
}
void set2()
{
    // int n = 10;
    // vi dp(n + 1, 0);
    // cout<<boardPath_01(0,n)<<endl;
    // cout << boardPath_02(0, n, dp) << endl;
    // cout << boardPath_03(0, n, dp) << endl;
    // display(dp);

    int n = 10;
    vi dp(n + 1, 0);
    vi Outcomes = {2, 3, 7, 5};
    // cout<<boardPath_01_giveOutcomes(0,n,Outcomes)<<endl;
    // cout << boardPath_02_giveOutcomes(0, n, Outcomes, dp) << endl;
    cout << boardPath_02_giveOutcomes(0, n, Outcomes, dp) << endl;
    display(dp);
}
int main(int args, char **argv)
{
    set2();
    return 0;
}