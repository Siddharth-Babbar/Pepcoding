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
void transpose(vector<vector<int>> & arr )
{
    for(int i=0;i<arr.size();i++)
     {
         for(int j=i;j<arr[0].size();j++)
          {
              swap(arr[i][j],arr[j][i]);
          }
     }
}
void swapc(vector<vector<int>> & arr)
{
    int c1=0;
    int c2=arr.size()-1;
    while(c1<c2)
     {
         for(int rows=0;rows<arr.size();rows++)
          {
              swap(arr[rows][c1],arr[rows][c2]);
          }
        c1++;
        c2--;
     }
}
void swapr(vector<vector<int>> & arr)
{
    int r1=0;
    int r2=arr.size()-1;
    while(r1<r2)
    {
        for(int i=0;i<arr.size();i++)
         {
             swap(arr[r1],arr[r2]);
         }
        r1++;
        r2--;
    }
}
void rotate90(vector<vector<int>> & arr, bool istrue)
{
  transpose(arr);
  if(istrue==true)
  {
      swapc(arr);
  }
  else
  {
      swapr(arr);
  }

 
}
int main(int args,char** argv)
{
    int n,m;
    cout<<"Plese enter the numbers:"<<endl;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m,10));
    bool isclockwise;
    cout<<"Enter whether to rotate the matrix clockwise or anticlockwise:"<<endl;
    cin>>isclockwise;
    input(arr);
    rotate90(arr,isclockwise);
    display(arr);
    
    return 0;
}