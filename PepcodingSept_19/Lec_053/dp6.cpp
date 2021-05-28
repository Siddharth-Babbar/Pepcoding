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
    cout << endl;
}
int coinsChangeCombination_01(vi &arr, int tar, int idx)
{
    if (tar == 0)
    {
        return 1;
    }
    int count = 0;
    for (int i = idx; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinsChangeCombination_01(arr, tar - arr[i], i);
        }
    }
    return count;
}
int coinsChangeCombination_03(vi &arr, int tar, vi &dp)
{
    dp[0] = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int t = 1; t <= tar; t++)
        {
            if (t - arr[i] >= 0)
            {
                dp[t] += dp[t - arr[i]];
            }
        }
    }
    return dp[tar];
}
int coinsChangePermutation_01(vi &arr, int tar)
{
    if (tar == 0)
    {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinsChangePermutation_01(arr, tar - arr[i]);
        }
    }
    return count;
}
int coinsChangePermutation_02(vi &arr, int tar, vi &dp)
{
    if (tar == 0)
    {
        return dp[tar] = 1;
    }
    int count = 0;
    if (dp[tar] != 0)
    {
        return dp[tar];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinsChangePermutation_02(arr, tar - arr[i], dp);
        }
    }
    return dp[tar] = count;
}
int coinsChangePermutation_03(vi &arr, int tar, vi &dp)
{
    dp[0] = 1;
    for (int t = 1; t <= tar; t++)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (t - arr[i] >= 0)
            {
                dp[t] += dp[t - arr[i]];
            }
        }
    }
    return dp[tar];
}
// leetcode 322
int minHeight_01(vector<int> &coins, int amount, int idx)
{
    if (amount == 0)
    {
        return 0;
    }
    int height = (int)1e8;
    for (int i = idx; i < coins.size(); i++)
    {
        if (amount - coins[i] >= 0)
        {
            int recAns = minHeight_01(coins, amount - coins[i], i);
            if (recAns < height)
            {
                height = recAns;
                // cout<<height<<" ";
            }
        }
    }
    return height != 1e8 ? height + 1 : height;
}
int minHeight_02(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (dp[amount] != 0)
    {
        return dp[amount];
    }
    int height = 1e8;
    for (int i = 0; i < coins.size(); i++)
    {
        if (amount - coins[i] >= 0)
        {
            int recAns = minHeight_02(coins, amount - coins[i], dp);
            if (recAns < height)
            {
                height = recAns;
            }
        }
    }
    dp[amount] = height != 1e8 ? height + 1 : height;
    return dp[amount];
}
int minHeight_03(vector<int> &coins, int amount, vector<int> &dp)
{
    dp[0] = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        for (int t = 1; t <= amount; t++)
        {
            if (t - coins[i] >= 0)
            {
                dp[t] = min(dp[t], dp[t - coins[i]]+1);
            }
        }
    }
    return dp[amount];
}
int coinChange(vector<int> &coins, int amount)
{
    // vector<int> dp(amount + 1, 0);
    vector<int> dp(amount + 1, 1e8);
    int ans = minHeight_03(coins, amount, dp);
    return ans != 1e8 ? ans : -1;
}
void set6_TargetType()
{
    vi arr = {2, 3, 5, 7};
    // vi arr={1,2,3};
    int tar = 10;
    // int tar=4;
    vi dp(tar + 1, 0);
    // cout<<coinsChangeCombination_01(arr,tar,0)<<endl;// tar=10,ans=5; tar=12,ans=7;
    // cout<<coinsChangeCombination_03(arr,tar,dp)<<endl;

    // cout<<coinsChangePermutation_01(arr,tar)<<endl;// tar=10,ans=16;tar=12,ans=35;
    // cout<<coinsChangePermutation_02(arr,tar,dp)<<endl;
    // cout<<coinsChangePermutation_03(arr,tar,dp)<<endl;

    cout << coinChange(arr, tar) << endl;

    // display(dp);
}
int main(int args, char **argv)
{
    set6_TargetType();
    return 0;
}