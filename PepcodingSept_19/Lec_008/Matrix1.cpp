#include<iostream>
#include<vector>

using namespace std;
void input(vector<vector<int>> & arr)
{
    for(int i=0; i<arr.size();i++)
     {
         for(int j=0;j<arr[0].size();j++)
          {
              cin>>arr[i][j];
          }
    
     }
}
void display(vector<vector<int>> & arr)
{
    for(vector<int> ar:arr)
     {
         for(int ele: ar)
          {
              cout<<ele<<" ";
          }
        cout<<endl;
     }
}
int main(int args,char** argv)
{
    int n,m;
    cout<<"Plese enter the numbers:"<<endl;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m,10));
   
    input(arr);
    display(arr);
    return 0;
}