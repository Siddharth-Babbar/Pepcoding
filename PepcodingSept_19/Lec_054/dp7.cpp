#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;
void display2D(vvi &dp)
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
void display(vi &dp)
{
    for (int ele : dp)
    {
        cout << ele << " ";
    }
    cout << endl;
}
int targetSum_01(vi &coins, int tar, int idx)
{
    if (tar == 0 || idx == -1)
    {
        return tar == 0 ? 1 : 0;
    }
    int count = 0;
    if (tar - coins[idx] >= 0)
    {
        count += targetSum_01(coins, tar - coins[idx], idx - 1);
    }
    count += targetSum_01(coins, tar, idx - 1);
    return count;
}
int targetSum_02(vi &coins, int tar, int idx, vvi &dp)
{
    // if (tar == 0 || idx < 0)
    // {
    //     return tar == 0 ? 1 : 0;
    // }
    if (tar == 0 || idx < 0)
    {
        if (tar == 0)
        {
            // dp[idx][tar] = 1;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[idx][tar] != 0)
    {
        return dp[idx][tar];
    }
    int count = 0;
    if (tar - coins[idx] >= 0)
    {
        count += targetSum_02(coins, tar - coins[idx], idx - 1, dp);
    }
    count += targetSum_02(coins, tar, idx - 1, dp);
    dp[idx][tar] = count;
    return count;
}
// int targetSum_03(vi &coins, int target, vvi &dp)
// {
//     dp[0][0] = 1;
//     for (int idx = 1; idx < coins.size(); idx++)
//     {
//         for (int tar = 0; tar <= target; tar++)
//         {
//             if (tar == 0)
//             {
//                 dp[idx][tar] = 1;
//             }
//             else
//             {
//                 int picked = 0, unpicked = 0;
//                 if (tar - coins[idx] >= 0)
//                 {
//                     picked = dp[idx - 1][tar - coins[idx]];
//                 }
//                 unpicked = dp[idx - 1][tar];
//                 dp[idx][tar] = picked + unpicked;
//             }
//         }
//     }
//     return dp[coins.size() - 1][target];
// }
int targetSum_03(vi & coins,int target , vvi & dp)
{
   for(int idx =0 ;idx< coins.size(); idx ++)
    {
        for(int tar=0;tar<=target;tar++)
         {
             
         }
    }
}
void set7()
{
    // vi coins = {0, 2, 3, 5, 7};
    vi coins = {2, 3, 5, 7};
    int tar = 10;
    vvi dp(coins.size(), vi(tar + 1, 0));
    // cout << targetSum_01(coins, tar, coins.size() - 1) << endl;
    // cout << targetSum_02(coins, tar, coins.size() - 1, dp) << endl;
    cout << targetSum_03(coins, tar, dp) << endl;

    display2D(dp);
}
int main(int args, char **argv)
{
    set7();
    return 0;
}