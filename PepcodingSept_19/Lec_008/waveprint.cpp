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
void waveprint(vector<vector<int>> & arr)
{
    for(int row=0;row<arr.size();row++)
     {
         if(row%2==0)
         {
          for(int col=0;col<arr[row].size();col++)
          cout<<arr[row][col]<<" ";
         }
         else
         {
           for(int col=arr[row].size()-1;col>=0;col--)
           cout<<arr[row][col]<<" ";
         }
         cout<<endl;
     }
}
int main(int args,char** argv)
{
    int n,m;
    cout<<"Please enter the number:"<<endl;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m,10));
    input(arr);
    waveprint(arr);
    

    return 0;
}