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
int PairAndSingleUp(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int count = 0;
    count += PairAndSingleUp(n - 1);
    count = count + (n - 1) * PairAndSingleUp(n - 2);

    return count;
}
int pairAndSingle_01(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int singleWays = pairAndSingle_01(n - 1);
    int pairUpWays = pairAndSingle_01(n - 2) * (n - 1);

    return singleWays + pairUpWays;
}
int pairAndSingle_02(int n, vi &dp)
{
    if (n <= 1)
    {
        dp[n] = 1;
        return 1;
    }

    int singleWays = pairAndSingle_02(n - 1, dp);
    int pairUpWays = pairAndSingle_02(n - 2, dp) * (n - 1);

    dp[n] = singleWays + pairUpWays;
    return singleWays + pairUpWays;
}
int pairAndSingle_03(int n, vi &dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            dp[i] = 1;
            continue;
        }

        int singleWays = dp[i - 1];
        int pairUpWays = dp[i - 2] * (i - 1);

        dp[i] = singleWays + pairUpWays;
    }
    return dp[n];
}
int pairAndSingle_04(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int a = 1;
    int b = 1;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = b + a * (i - 1);
        a = b;
        b = ans;
    }
    return ans;
}
//Leetcode 45
int Minjump_01(int idx, vector<int> &nums)
{
    if (idx == nums.size() - 1)
    {
        return 0;
    }
    if (nums[idx] == 0)
    {
        return (int)1e7;
    }
    int minAns = 1e7;
    for (int jump = 1; jump <= nums[idx] && idx + jump < nums.size(); jump++)
    {
        int minJump = Minjump_01(idx + jump, nums);
        if (minJump != 1e7 && minJump + 1 < minAns)
        {
            minAns = minJump + 1;
        }
    }
    return minAns;
}
int Minjump_02(int idx, vector<int> &nums, vector<int> &dp)
{
    if (idx == nums.size() - 1)
    {
        return 0;
    }
    if (nums[idx] == 0)
    {
        return (int)1e7;
    }
    if (dp[idx] != 0)
    {
        return dp[idx];
    }
    int minAns = 1e7;
    for (int jump = 1; jump <= nums[idx] && idx + jump < nums.size(); jump++)
    {
        int minJump = Minjump_02(idx + jump, nums, dp);
        if (minJump != 1e7 && minJump + 1 < minAns)
        {
            minAns = minJump + 1;
        }
    }
    dp[idx] = minAns;
    return minAns;
}
int Minjump_03( vector<int> &nums, vector<int> &dp)
{
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i == nums.size() - 1)
        {
            continue;
        }
        if (nums[i] == 0)
        {
            return (int)1e7;
        }
        int minAns = 1e7;
        for (int jump = 1; jump <= nums[i] && i + jump < nums.size(); jump++)
        {
            int minJump =;
            if (minJump != 1e7 && minJump + 1 < minAns)
            {
                minAns = minJump + 1;
            }
        }
        dp[i] = minAns;
    }
    return dp[0];
}
int jump(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    // int ele = Minjump_02(0, nums, dp);
    int ele = Minjump_03(nums,dp);
    display(dp);
    return ele;
}
void set3()
{
    //    int n=10;
    //    vi dp(n+1,0);
    //    cout<<PairAndSingleUp(n)<<endl;
    //    cout<<pairAndSingle_01(n)<<endl;
    //    cout<<pairAndSingle_02(n,dp)<<endl;
    //    cout<<pairAndSingle_03(n,dp)<<endl;
    //    cout<<pairAndSingle_04(n)<<endl;
    //    display(dp);

    vi nums = {4, 3, 5, 0, 9, 2, 6, 7, 6, 8, 9};
    cout << jump(nums) << endl;
}
int main(int args, char **argv)
{
    set3();
    return 0;
}