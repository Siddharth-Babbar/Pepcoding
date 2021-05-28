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
void spiral1(vector<vector<int>> & arr)
{
    int dir=0;
    int r=0;
    int c=0;
    while(true)
    {
        dir=(dir+ arr[r][c])%4;
        if(dir==0)
        {
          c++;
          if(c==arr[0].size())
          {
              cout<<r<<","<<c-1;
              break;
          }

        }
        else if(dir==1)
        {
          r++;
          if(r==arr.size())
          {
              cout<<r-1<<","<<c;
              break;
          }
        }
        else if(dir==2)
        {
            c--;
            if(c==-1)
            {
                cout<<r<<","<<c+1;
                break;
            }

        }
        else
        {
            r--;
            if(r==-1)
            {
                cout<<r+1<<","<<c;
                break;
            }
        }
    }
}
int main(int args,char** argv)
{
    int n,m;
    cout<<"Please enter the number:"<<endl;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int> (m,10));
    input(arr);
    spiral1(arr);
    

    return 0;
}