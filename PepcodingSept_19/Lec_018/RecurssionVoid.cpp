#include<iostream>
#include<vector>
#include<string>

using namespace std;
int nqueenCombi(vector<bool> & box,int qpsf,int tnq,int lqpl,string ans)
{
    if(qpsf==tnq)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    for(int i=lqpl;i<box.size();i++)
     {
         
         count+=nqueenCombi(box,qpsf+1,tnq,i+1,ans+"b"+to_string(i)+"q"+to_string(qpsf));
         
     }
    return count;
}
int nqueenPermu(vector<bool> & box,int qpsf,int tnq,int lqpl,string ans)
{
    if(qpsf==tnq)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    for(int i=lqpl;i<box.size();i++)
     {
         if(!box[i])
          {
              box[i]=true;
              count+=nqueenPermu(box,qpsf+1,tnq,0,ans+"b" + to_string(i)+"q" + to_string(qpsf));
              box[i]=false;
          }
     }
    return count;
}
int Queen2DCombi(vector<vector<bool>> & board,int lqpl,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    for(int i=lqpl;i<board.size()*board[0].size();i++)
     {
         int x=i/board[0].size();
         int y=i/board[0].size();
         count+=Queen2DCombi(board,i+1,qpsf+1,tnq,ans+"("+to_string(x)+","+to_string(y)+") ");
     }
    return count;
}
int Queen2DPermu(vector<vector<bool>> & board,int lqpl,int qpsf,int tnq,string ans)
{
    if(qpsf==tnq)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    for(int i=lqpl;i<board.size()*board[0].size();i++)
     {
         int x=i/board[0].size();
         int y=i%board[0].size();
         if(!board[x][y])
         {
          board[x][y]=true;
          count+=Queen2DPermu(board,0,qpsf+1,tnq,ans+"("+to_string(x)+","+to_string(y)+") ");
          board[x][y]=false;
         }
     }
    return count;
}

void CombiPermu()
{
    vector<bool> box(5,false);
    vector<vector<bool>> board(4,vector<bool>(4,false));
    // cout<<nqueenCombi(box,0,3,0,"");
    // cout<<nqueenPermu(box,0,3,0,"");
    // cout<<Queen2DCombi(board,0,0,4,"");
    cout<<Queen2DPermu(board,0,0,4,"");
}
void solve()
{
   CombiPermu();
}
int main(int args,char ** argv)
{
    solve();
    return 0;
}