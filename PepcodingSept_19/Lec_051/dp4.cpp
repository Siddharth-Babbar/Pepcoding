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
int divideInKSubsets_01(int n, int k)
{
    if (n == k || k == 1)
    {
        return 1;
    }
    if (n < k)
    {
        return 0;
    }
    // if(k==1)
    //  {
    //      return 1;
    //  }
    int startingofNewSet = divideInKSubsets_01(n - 1, k - 1);
    int totalGroups = divideInKSubsets_01(n - 1, k);

    int totalSets = totalGroups * k;

    return startingofNewSet + totalSets;
}
int divideInKSubsets_02(int n, int k, vvi &dp)
{
    if (n == k || k == 1)
    {
        //  cout<<n<<" "<<k<<endl;
        dp[n][k] = 1;
        return 1;
    }
    if (n < k)
    {
        dp[n][k] = 0;
        return 0;
    }
    if (dp[n][k] != 0)
    {
        return dp[n][k];
    }

    int startingofNewSet = divideInKSubsets_02(n - 1, k - 1, dp);
    int totalGroups = divideInKSubsets_02(n - 1, k, dp);

    int totalSets = totalGroups * k;

    return dp[n][k] = startingofNewSet + totalSets;
}
int divideInKSubsets_03(int n, int k, vvi &dp)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < j)
            {
                continue;
            }
            if (i == j || j == 1)
            {
                dp[i][j] = 1;
                continue;
            }

            int startingOfNewSet = dp[i - 1][j - 1];
            int totalGroups = dp[i - 1][j];

            int totalSets = totalGroups * j;

            dp[i][j] = startingOfNewSet + totalSets;
        }
    }
    return dp[n][k];
}
vvi dirArr = {{-1, 1}, {0, 1}, {1, 1}};
int goldMine_01(int x, int y, vvi &arr)
{
    if (y == arr[0].size() - 1)
    {
        return arr[x][y];
    }
    int max_ = -1;
    int ans = 0;
    for (vi e : dirArr)
    {
        int r = x + e[0];
        int c = y + e[1];

        if (r >= 0 && c >= 0 && r < arr.size() && c < arr[0].size())
        {
            ans = goldMine_01(r, c, arr);
        }
        max_ = max(max_, ans);
        // cout<<max_<<" ";
    }
    return max_ + arr[x][y];
}
int goldMine_02(int x, int y, vvi &arr, vvi &dp)
{
    if (y == arr[0].size() - 1)
    {
        return dp[x][y] = arr[x][y];
    }
    if (dp[x][y] != 0)
    {
        return dp[x][y];
    }
    int max_ = -1;
    int ans = 0;
    for (vi ele : dirArr)
    {
        int r = x + ele[0];
        int c = y + ele[1];

        if (r >= 0 && c >= 0 && r < arr.size() && c < arr[0].size())
        {
            ans = goldMine_02(r, c, arr, dp);
        }
        max_ = max(max_, ans);
    }
    dp[x][y] = max_ + arr[x][y];
    return max_ + arr[x][y];
}
int goldMine_03(vvi & arr,vvi & dp)
{
    for(int x=0;x<arr.size();x++)
     {
         for(int y=arr[0].size()-1;y>=0;y--)
          {
            if(y == arr[0].size()-1)
             {
                 dp[x][y]=arr[x][y];
                 continue;
             }
            for(vi ele:dirArr)
             {
                 int r=x + ele[0];
                 int c=y + ele[1];

                 if(r>=0 && c>=0 && r<arr.size() && c<arr[0].size())
                  {
                      dp[x][y]=max(dp[x][y],dp[r][c]);
                  }
             }
          }
     }
}
int goldMine(vvi &arr)
{
    // int maxAns_ = -1;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     maxAns_ = max(maxAns_, goldMine_01(i, 0, arr));
    // }
    // return maxAns_;

    int maxAns_ = -1;
    vvi dp(arr.size(), vi(arr[0].size(), 0));
    for (int i = 0; i < arr.size(); i++)
    {
        maxAns_ = max(maxAns_, goldMine_02(i, 0, arr, dp));
    }
    display2D(dp);
    cout<<endl;
    return maxAns_;
}
void set4()
{
    //    int n=5;
    //    int k=3;
    //    vvi dp(n+1,vi(k+1,0));
    //    cout<<divideInKSubsets_01(n,k)<<endl;
    //    cout<<divideInKSubsets_02(n,k,dp)<<endl;
    //    cout<<divideInKSubsets_03(n,k,dp)<<endl;

    vvi arr = {{1, 3, 3},
               {2, 1, 4},
               {0, 6, 4}};
    cout << goldMine(arr) << endl;

    //    display2D(dp);
}
int main(int args, char **argv)
{
    set4();
    return 0;
}