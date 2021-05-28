#include<iostream>
#include<vector>

using namespace std;
void input(vector<vector<int>> & arr)
{
    for(int i=0;i<arr.size();i++)
     {
         for(int j=0;j<arr[0].size();j++)
          {
              cin>>arr[i][j];
          }
     }
}
void output(vector<vector<int>> & arr)
{
    for(int i=0;i<arr.size();i++)
     {
         for(int j=0;j<arr[i].size();j++)
          {
              cout<<arr[i][j];
          }
          cout<<endl;
     }
}
void spiral2(vector<vector<int>> & arr)
{
    int minr=0;
    int minc=0;
    int maxr=arr.size()-1;
    int maxc=arr[0].size()-1;
    int tre=arr.size()*arr[0].size();
    while(tre!=0)  
     {
         for(int i=minc;i<=maxc && tre!=0;i++)
          {
              cout<<arr[minr][i]<<" ";
              tre--;
          }

          minr++;
           for(int i=minr;i<=maxr && tre!=0;i++)
          {
              cout<<arr[i][maxc]<<" ";
              tre--;
          }
          maxc--;
           for(int i=maxc;i>=minc && tre!=0;i--)
          {
              cout<<arr[maxr][i]<<" ";
              tre--;
          }
          maxr--;
           for(int i=maxr;i>=minr && tre!=0;i--)
          {
              cout<<arr[i][minc]<<" ";
              tre--;
          }
            
          minc++;
     }
}
int main(int args,char** argv)
{
    int n,m;
    cout<<"Please enter the number:"<<endl;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m,10));
    input(arr);
    spiral2(arr);
    

    return 0;
}