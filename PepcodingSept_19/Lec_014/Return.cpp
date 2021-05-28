#include<iostream>
#include<vector>
#include<string>

using namespace std;

//=========================
bool isSafe(int x,int y,int er,int ec,vector<vector<bool>> & board)
{
    if(x<0||y<0||x>er||y>ec||board[x][y])
     {
         return false;
     }
    return true;
}
// bool isSafeRM(int x,int y,int er,int ec,vector<vector<bool>> & board,vector<vector<int>> & bomb)
// {
//     int i=0,j=0;
//     while((i!=bomb.size()-1) && (j!=bomb[1].size()-1))
//      {

//         if(x<0||y<0||x>er||y>ec||board[x][y]||(x==bomb[i][0]&&y==bomb[0][j]))
//          {
//             return false;
//          }
//         i++;
//         j++;
            
//      }
//     return true;
// }
vector<vector<int>> direction={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
vector<string> dir={"R","1","U","2","L","3","D","4"};
int floodfill(int sr,int sc,int er,int ec,vector<vector<bool>> & board,string ans)
{
    if(sr==er && sc==ec )
     {
        cout<<ans<<endl;
         return 1;
     }
     board[sr][sc]=true;
     int count=0;
     for(int d=0;d<8;d++)
      {
          int x=sr+direction[d][0];
          int y=sc+direction[d][1];
          if(isSafe(x,y,er,ec,board))
           {
            count+= floodfill(x,y,er,ec,board,ans+dir[d]);
           }
          
      }
     board[sr][sc]=false;
     return count;
}
int RatAndMaze(int sr,int sc,int er,int ec,vector<vector<bool>> & board,string ans)
{
    if(sr==er && sc==ec )
     {
        cout<<ans<<endl;
         return 1;
     }
     board[sr][sc]=true;
     int count=0;
     for(int d=0;d<8;d++)
      {
          int x=sr+direction[d][0];
          int y=sc+direction[d][1];
          if(isSafe(x,y,er,ec,board))
           {
            count+= RatAndMaze(x,y,er,ec,board,ans+dir[d]);
           }
          
      }
     board[sr][sc]=false;
     return count;
}
vector<string> simplePermutation(string str)
{
    if(str.size()==0)
     {
        vector<string> base;
        base.push_back(str);
        return base;
     }
    char ch=str[0];
    string newstr=str.substr(1);
    vector<string> myans;
    vector<string> smallans=simplePermutation(newstr);
    for(string s:smallans)
     {
         for(int i=0;i<=s.length();i++)
          {
              string st=s.substr(0,i)+ch+s.substr(i);
              myans.push_back(st);
          }
     }
     return myans;

}
void floodFill()
{
    vector<vector<bool>> board(3,(vector<bool>(3,false)));
    cout<<floodfill(0,0,2,2,board,"");
}
void ratandmaze()
{
   vector<vector<bool>> board(3,(vector<bool>(3,false)));
   board[0][0]=true;
   board[1][0]=true;
   board[2][2]=true;
   cout<<RatAndMaze(1,0,1,2,board,"");
}
void mazepath()
{
  
  
}
void basic()
{
    // mazepath();
    //  floodFill();
    // vector<string> ans=simplePermutation("abc");
    // for(string s:ans)
    //      cout<<s<<endl;
    //  }
     ratandmaze();

}
void solve()
{ 
    basic();

}
int main(int args,char** argv)
{
    solve();
    return 0;
}
