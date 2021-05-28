#include <iostream>
#include <vector>

using namespace std;
#define vi vector<int>
#define vvi vector<vi>

void display(vi &dp)
{
    for (int ele : dp)
    {
        cout << ele << " ";
    }
    cout << endl;
}
void display2D(vvi &dp)
{
    for (vi &s : dp)
    {
        for (int &ele : s)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
int fibo_01(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int ans = fibo_01(n - 1) + fibo_01(n - 2);
    return ans;
}
int fibo_02(int n, vi &dp)
{
    if (n <= 1)
    {
        dp[n] = n;
        return n;
    }
    if (dp[n] != 0)
    {
        return dp[n];
    }
    int ans = fibo_02(n - 1, dp) + fibo_02(n - 2, dp);
    dp[n] = ans;
    return ans;
}
int fibo_03(int n, vi &dp)
{
    for (int i = 0; i <= n; i++)
    {
        if (i <= 1)
        {
            dp[i] = i;
            continue;
        }
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}int MazePathHV_01(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        return 1;
    }
    int count = 0;
    if (sr + 1 <= er)
    {
        count += MazePathHV_01(sr + 1, sc, er, ec);
    }
    if (sc + 1 <= ec)
    {
        count += MazePathHV_01(sr, sc + 1, er, ec);
    }
    return count;
}
int MazePathHV_02(int sr, int sc, int er, int ec, vvi &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }
    int count = 0;
    if (dp[sr][sc] != 0)
    {
        return dp[sr][sc];
    }
    if(er==ec && dp[sc][sr]!=0)
     {
         return dp[sc][sr];
     }
    if (sr + 1 <= er)
    {
        count += MazePathHV_02(sr + 1, sc, er, ec, dp);
    }
    if (sc + 1 <= ec)
    {
        count += MazePathHV_02(sr, sc + 1, er, ec, dp);
    }
    dp[sr][sc] = count;
    // if (er == ec)
    // {
    //     dp[sc][sr] = count;
    // }
    return count;
}
int MazePathHV_03(int er, int ec, vvi &dp)
{
    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {

            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;

            if (sr + 1 <= er)
            {
                count += dp[sr + 1][sc];
            }
            if (sc + 1 <= ec)
            {
                count += dp[sr][sc + 1];
            }
            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}
int MazePathHVD_01(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        return 1;
    } 
    int count = 0;
    if (sr + 1 <= er)
    {
        count += MazePathHVD_01(sr + 1, sc, er, ec);
    }
    if (sc + 1 <= ec)
    {
        count += MazePathHVD_01(sr, sc + 1, er, ec);
    }
    if (sc + 1 <= ec && sr + 1 <= er)
    {
        count += MazePathHVD_01(sr + 1, sc + 1, er, ec);
    }
    return count;
}
int MazePathHVD_02(int sr, int sc, int er, int ec, vvi &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }
    int count = 0;
    if (dp[sr][sc] != 0)
    {
        return dp[sr][sc];
    }
    if(er==ec && dp[sc][sr]!=0)
     {
         return dp[sc][sr];
     }
    if (sr + 1 <= er)
    {
        count += MazePathHVD_02(sr + 1, sc, er, ec, dp);
    }
    if (sc + 1 <= ec)
    {
        count += MazePathHVD_02(sr, sc + 1, er, ec, dp);
    }
    if (sc + 1 <= ec && sr + 1 <= er)
    {
        count += MazePathHVD_02(sr + 1, sc + 1, er, ec, dp);
    }
    dp[sr][sc] = count;
    if (er == ec)
    {
        dp[sc][sr] = count;
    }
    return count;
}
int MazePathHVD_03(int er, int ec, vvi &dp)
{
    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {

            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;

            if (sr + 1 <= er)
            {
                count += dp[sr + 1][sc];
            }
            if (sc + 1 <= ec)
            {
                count += dp[sr][sc + 1];
            }
            if (sc + 1 <= ec && sr + 1 <= er)
            {
                count += dp[sr + 1][sc + 1];
            }
            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}
int MazePathMulti_01(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        return 1;
    }
    int count = 0;
    for (int jump = 1; sr + jump <= er; jump++)
    {
        count += MazePathMulti_01(sr + jump, sc, er, ec);
    }
    for (int jump = 1; sc + jump <= ec; jump++)
    {
        count += MazePathMulti_01(sr, sc + jump, er, ec);
    }
    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
    {
        count += MazePathMulti_01(sr + jump, sc + jump, er, ec);
    }
    return count;
}
int MazePathMulti_02(int sr, int sc, int er, int ec, vvi &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }
    int count = 0;
    if (dp[sr][sc] != 0)
    {
        return dp[sr][sc];
    }
    for (int jump = 1; sr + jump <= er; jump++)
    {
        count += MazePathMulti_02(sr + jump, sc, er, ec, dp);
    }
    for (int jump = 1; sc + jump <= ec; jump++)
    {
        count += MazePathMulti_02(sr, sc + jump, er, ec, dp);
    }
    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
    {
        count += MazePathMulti_02(sr + jump, sc + jump, er, ec, dp);
    }
    dp[sr][sc] = count;
    return count;
}
int MazePathMulti_03(int er, int ec, vvi &dp)
{
    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;
            for (int jump = 1; sr + jump <= er; jump++)
            {
                count += dp[sr + jump][sc];
            }
            for (int jump = 1; sc + jump <= ec; jump++)
            {
                count += dp[sr][sc + jump];
            }
            for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
            {
                count += dp[sr + jump][sc + jump];
            }
            dp[sr][sc] = count;
        }
    }
    return dp[0][0];
}
void set1()
{
    // int n = 10;
    // vi dp(n + 1, 0);
    //    cout<<fibo_01(n)<<endl;
    // cout << fibo_02(n, dp) << endl;
    // cout << fibo_03(n, dp) << endl;
    // display(dp);

    // int n = 2;
    // vvi dp(n + 1, vi((n + 1), 0));
    // cout<<MazePathHV_01(0,0,n,n)<<endl;
    // cout << MazePathHV_02(0, 0, n, n, dp) << endl;
    // cout << MazePathHV_03(n, n, dp) << endl;
    // display2D(dp);

    int n = 2;
    vvi dp(n + 1, vi((n + 1), 0));
    // cout<<MazePathHVD_01(0,0,n,n)<<endl;
    cout << MazePathHVD_02(0, 0, n, n, dp) << endl;
    // cout << MazePathHVD_03(n, n, dp) << endl;
    display2D(dp);

    // int n = 2;
    // vvi dp(n + 1, vi((n + 1), 0));
    // cout << MazePathMulti_01(0, 0, n, n) << endl;
    // cout << MazePathMulti_02(0, 0, n, n, dp) << endl;
    // cout << MazePathMulti_03(n, n, dp) << endl;
    // display2D(dp);
}
int main(int args, char **argv)
{
    set1();
    return 0;
}