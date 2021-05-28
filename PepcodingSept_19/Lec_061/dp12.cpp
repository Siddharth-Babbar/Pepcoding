#include<iostream>
#include<vector>

#define vi vector<int>
#define vvi vector<vi>

using namespace std;
// int longestCommonSubsequence(string s1,string s2)// wrong approach
// {
//     int max=0;
//     int idx=0;
//     for(int i=0;i<s1.length();i++)
//      {
//         for(int j=idx;j<s2.length();j++)
//          {
//              cout<<s1[i]<<" "<<s2[j]<<endl;
//              if(s1[i] == s2[j])
//               {
//                 //   cout<<"Hi";
//                   max++;
//                   idx=j+1;
//                   continue;
//               }
//          }
//      }
//     return max;
// }
int longestCommonSubsequence_01(string str1,int i,string str2,int j)
{
    if(i == str1.length() || j == str2.length())
     {
         return 0;
     }
    
    int Ans=0;
    if(str1[i] == str2[j])
     {
         Ans=longestCommonSubsequence_01(str1,i+1,str2,j+1) + 1 ;
     }
    else
     {
         Ans=max(longestCommonSubsequence_01(str1,i+1,str2,j),longestCommonSubsequence_01(str1,i,str2,j+1));
     }
    
    return Ans;
    
    
}
int longestCommonSubsequence_02(string str1,int i,string str2,int j,vvi & dp)
{
    if(i == str1.length() || j == str2.length())
     {
         return  0;
     }
    
    if(dp[i][j]!=0)
     {
         return dp[i][j];
     }
    
    int Ans=0;
    if(str1[i] == str2[j])
     {
         Ans=longestCommonSubsequence_02(str1,i+1,str2,j+1,dp);
     }
    else
     {
         Ans=max(longestCommonSubsequence_02(str1,i+1,str2,j,dp),longestCommonSubsequence_02(str1,i,str2,j+1,dp));
     }

    return dp[i][j]=Ans;
    
}
void set12()
{
    // string str1={"ABCDGH"};
    // string str2={"AEDFFHR"};
    string str1={"AGGTAB"};
    string str2={"GXTXAYB"};
    // string s1={"abcd"};
    // string s2={"aabcd"};


    cout<< longestCommonSubsequence_01(str1,0,str2,0)<<endl;
}
int main(int args,char** argv)
{
    set12();
    return 0;
}