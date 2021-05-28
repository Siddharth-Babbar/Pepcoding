#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

using namespace std;
void display(vi &dp)
{
    for (int ele : dp)
    {
        cout << ele << " ";
    }
}
int LIS_01(vi &arr, int idx, string ans)
{
    if (idx == arr.size())
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    cout << ans << endl;
    // count += LIS_01(arr, idx + 1, ans);
    for (int i = idx + 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[idx])
        {
            count += LIS_01(arr, i, ans + to_string(arr[i]) + " ");
        }
    }
    // count += LIS_01(arr, idx + 1, ans);
    return count;
}
vi LIS_03(vi &arr)
{
    vi dp(arr.size(), 1);
    int max_ = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_ = max(max_, dp[i]);
    }
    cout << max_ << endl;
    return dp;
}

void set9()
{
    vi arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     cout << LIS_01(arr, i, to_string(arr[i])+" ") << endl;
    // }
    vi LIS = LIS_03(arr);
    display(LIS);
}
int main(int args, char **argv)
{
    set9();
    return 0;
}   