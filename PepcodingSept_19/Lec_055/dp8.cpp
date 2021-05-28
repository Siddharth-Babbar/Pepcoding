#include <iostream>
#include <vector>

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

using namespace std;
void Idisplay(vi &dp)
{
    for (int ele : dp)
    {
        cout << ele << " ";
    }
    cout << endl;
}
void Idisplay2D(vvi &dp)
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
void Bdisplay(vb &dp)
{
    for (bool ele : dp)
    {
        cout << ele << " ";
    }
    cout << endl;
}
void Bdisplay2D(vvb &dp)
{
    for (vb e : dp)
    {
        for (bool ele : e)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
vvb isPalindromeSubString(string str)
{
    vvb dp(str.length(), vb(str.length(), false));
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); j++, i++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else if (str[i] == str[j])
            {
                if (gap == 1)
                {
                    dp[i][j] = true;
                }
                else if (dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                }
            }
        }
    }
    return dp;
}
int LongestPalindromicSubString(string str, vvi &dp)
{
    vvb isPalin = isPalindromeSubString(str);
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (gap == 1 && str[i] == str[j])
            {

                dp[i][j] = 2;
            }
            else if (gap == 1 && isPalin[i + 1][j - 1])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][str.length() - 1];
}
int LongestPalindromicSubSequence(string str, vvi &dp)
{
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (str[i] == str[j])
            {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][str.length() - 1];
}
int countPalindromicSubSequence(string str, vvi &dp)
{
    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
            }
            else if (str[i] == str[j])
            {
                dp[i][j] += dp[i + 1][j - 1] + 1;
                dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    return dp[0][str.length() - 1];
}
void set8()
{
    // string str = {"abccbdefeg"};
    // vvb ans = isPalindromeSubString(str);
    // Bdisplay2D(ans);

    // string str = {"efabcbadd"};
    // string str = {"acbdebafg"};
    // vvi dp(str.length(), vi(str.length(), 0));
    // cout << LongestPalindromicSubString(str, dp) << endl;
    // Idisplay2D(dp);

    // string str = {"acbdebafg"};
    // vvi dp(str.length(), vi(str.length(), 0));
    // cout << LongestPalindromicSubSequence(str, dp) << endl;
    // Idisplay2D(dp);

    string str = {"amrmsra"};
    vvi dp(str.length(), vi(str.length(), 0));
    cout << countPalindromicSubSequence(str, dp) << endl;
    Idisplay2D(dp);
}
int main(int args, char **argv)
{
    set8();
    return 0;
}
