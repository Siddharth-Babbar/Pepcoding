#include<iostream>
#include<vector>
#include<list>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;
// int maxSquareAns=0;
// int MaxSquareSubMatrix(int r,int c,vvi &arr)
// {
//     if(r == arr.size() || c == arr[0].size())
//      {
//          return 0;
//      }
//     int maxSquare=(int)1e7;
//     int h=MaxSquareSubMatrix(r,c+1,arr);
//     int v=MaxSquareSubMatrix(r+1,c,arr);
//     int d=MaxSquareSubMatrix(r+1,c+1,arr);

//     if(arr[r][c]==1)
//      {
//          maxSquare=min(h,min(v,d))+1;
//      }
//     int ans=maxSquare!=(int)1e7?maxSquare:0;
//     maxSquareAns=max(maxSquareAns,ans);
//     return ans;
// }
void display2D(vvi &dp)
{
    for(vi e:dp)
     {
         for(int ele:e)
          {
              cout<<ele<<" ";
          }
         cout<<endl;
     }
}
void display(vi & dp)
{
    for(int ele:dp)
     {
         cout<<ele<<" ";
     }
}
int maxSquareAns_01=0;
int maxSquareOf1s_01(int r,int c,vvi& arr)
{
    if(r == arr.size() || c== arr[0].size())
     {
         return 0;
     }
    int minPossibleSquare=0;
    int down=maxSquareOf1s_01(r+1,c,arr);
    int diag=maxSquareOf1s_01(r+1,c+1,arr);
    int right=maxSquareOf1s_01(r,c+1,arr);

    if(arr[r][c]==1)
     {
         minPossibleSquare=min(down,min(diag,right))+1;
     }
    maxSquareAns_01=max(maxSquareAns_01,minPossibleSquare);
    return minPossibleSquare;
}
int maxSquareAns_02=0;
int maxSquareOf1s_02(int r,int c,vvi& arr,vvi &dp)
{
    if(r == arr.size() || c== arr[0].size())
     {
         return 0;
     }
    int minPossibleSquare=0;
    if(dp[r][c]!=-1)
     {
         return dp[r][c];
     }
    int down=maxSquareOf1s_02(r+1,c,arr,dp);
    int diag=maxSquareOf1s_02(r+1,c+1,arr,dp);
    int right=maxSquareOf1s_02(r,c+1,arr,dp);

    if(arr[r][c]==1)
     {
         minPossibleSquare=min(down,min(diag,right))+1;
     }
    dp[r][c]=minPossibleSquare;
    maxSquareAns_02=max(maxSquareAns_02,minPossibleSquare);
    return minPossibleSquare;
}
int maxSquareOf1s_03(vvi & arr,vvi & dp)
{
    int n=arr.size()-1;
    int m=arr[0].size()-1;
    int maxSquareAns_03=0;
    for(int r=n;r>=0;r--)
     {
         for(int c=m;c>=0;c--)
          {
              if(arr[r][c]==1)
               {
                   dp[r][c]=min(dp[r+1][c],min(dp[r][c+1],dp[r+1][c+1]))+1;
               }
              else
               {
                  dp[r][c]=0;
               }
             
             maxSquareAns_03=max(maxSquareAns_03,dp[r][c]);
              
          }
     }
    return maxSquareAns_03;
}
int tileFloor_01(int n ,int m)
{
    if(n<=m)
     {
         return n==m?2:1;
     }
    
    int horizontal=tileFloor_01(n-1,m);
    int vertical=tileFloor_01(n-m,m);

    return horizontal + vertical;
}
int tileFloor_02(int n,int m,vi & dp)
{
    if(n<=m)
     {
         dp[n] = (n==m)?2:1;
         return dp[n];
     }
    
    if(dp[n]!=0)
     {
         return dp[n];
     }
    
    int horizontal=tileFloor_02(n-1,m,dp);
    int vertical=tileFloor_02(n-m,m,dp);

    dp[n]=horizontal + vertical;

    return dp[n];
}
int tileFloor_03(int n,int m,vi & dp)
{
    for(int i=0;i<=n;i++)
     {
         if(i<=m)
          {
              dp[i]=(i==m)?2:1;
              continue;
          }
         dp[i]=dp[i-1]+dp[i-m];
     }
    return dp[n];
}
int tileFloor_04(int n,int m)
{
    if(n<=m)
     {
         return (n==m)?2:1;
     }
    list<int> ll;
    for(int i=1;i<=m;i++)
     {
         ll.push_back(1);
     }
    for(int i=m;i<=n;i++)
     {
         ll.push_back(ll.front()+ll.back());
         ll.pop_front();
     }
    return ll.back();
     
}
void set5()
{
    vvi arr={{0,1,1,0,1},
             {1,1,0,1,0},
             {0,1,1,1,0},
             {1,1,1,1,0},
             {1,1,1,1,1},
             {0,0,0,0,0}};
    // MaxSquareSubMatrix(0,0,arr);
    // cout<<maxSquareAns<<endl;

    // maxSquareOf1s_01(0,0,arr);
    // cout<<maxSquareAns_01<<endl;

    // vvi dp(arr.size(),vi(arr[0].size(),-1));
    // maxSquareOf1s_02(0,0,arr,dp);
    // cout<<maxSquareAns_02<<endl;
    // display2D(dp);

    // vvi dp(arr.size(),vi(arr[0].size(),-1));
    // cout<<maxSquareOf1s_03(arr,dp)<<endl;
    // display2D(dp);

    int n=17,m=6;
    // cout<<tileFloor_01(n,m)<<endl;// n=7,m=4,ans=5; n=17,m=6,ans=34;
    vi dp(n+1,0);
    // cout<<tileFloor_02(n,m,dp)<<endl;
    // cout<<tileFloor_03(n,m,dp)<<endl;
    cout<<tileFloor_04(n,m)<<endl;
    display(dp);


}
int main(int args,char** argv)
{
    set5();
    return 0;
}