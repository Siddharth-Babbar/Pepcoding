#include <iostream>
#include <vector>

using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define vc vector<char>
#define vvc vector<vc>
int Queens(vb &row, vb &col, vb &diag, vb &adiag, int r, int tnq, string ans)
{
    if (r == row.size() || tnq == 0)
    {
        if (tnq == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int c = 0; c < col.size(); c++)
    {
        if (!col[c] && !diag[r - c + col.size() - 1] && !adiag[r + c])
        {
            col[c] = true;
            diag[r - c + col.size() - 1] = true;
            adiag[r + c] = true;
            count += Queens(row, col, diag, adiag, r + 1, tnq - 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ");
            col[c] = false;
            diag[r - c + col.size() - 1] = false;
            adiag[r + c] = false;
        }
    }
    return count;
}
int Queens2(int col, int diag, int adiag, int r, int tnq, string ans)
{
    int n = 4;
    if (r == n || tnq == 0)
    {
        if (tnq == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int c = 0; c < n; c++)
    {
        int w = 1 << c;
        int x = 1 << (r - c + n - 1);
        int y = 1 << (r + c);
        if (!(col & w) && !(diag & x) && !(adiag & y))
        {
            col ^= w;
            diag ^= x;
            adiag ^= y;
            count += Queens2(col, diag, adiag, r + 1, tnq - 1, ans + "(" + to_string(r) + "," + to_string(c) + ") ");
            col ^= w;
            diag ^= x;
            adiag ^= y;
        }
    }
    return count;
}
bool IsSafeToPlaceNumber(vvi &board,int x,int y,int num)
{
   for(int i=0;i<9;i++)
    {
        if(board[x][i]==num)
         {
             return false;
         }
    }
    for(int i=0;i<9;i++)
     {
        if(board[i][y]==num)
         {
             return false;
         }
     }
    int nx=(x/3)*3;
    int ny=(y/3)*3;
    for(int i=0;i<3;i++)
     {
         for(int j=0;j<3;j++)
          {
              if(board[nx+i][ny+j]==num)
               {
                   return false;
               }
          }
     }
    return true;
}
void display(vvi &board)
{
   for(vi i:board)
    {
        for(int ele:i)
         {
             cout<<ele<<" ";
         }
        cout<<endl;
    }
   cout<<endl;
}
int call1=0;
int call2=0;;
int call3=0;
int Sudoku_01(vvi & board,int idx)
{
    call1++;
    if(idx==81)
     {
         display(board);
         return 1;
     }
    int count=0;
    int x=idx/9;
    int y=idx%9;
    if(board[x][y]==0)
     {
      for(int num=1;num<=9;num++)
       {
          if(IsSafeToPlaceNumber(board,x,y,num))
           {
            board[x][y]=num;
            count+=Sudoku_01(board,idx+1);
            board[x][y]=0;
          }
       }
     }
    else
     {
        count+=Sudoku_01(board,idx+1);
     }
    
    return count;
}
int Sudoku_02(vvi & board,vi & call,int idx)
{
    call2++;
    if(idx==call.size())
     {
         display(board);
         return 1;
     }
    int count=0;
    int x=call[idx]/9;
    int y=call[idx]%9;
    for(int num=1;num<=9;num++)
     {
        if(IsSafeToPlaceNumber(board,x,y,num))
         {
           board[x][y]=num;
           count+=Sudoku_02(board,call,idx+1);
           board[x][y]=0;
         }
     }
    return count;
}
int Sudoku_03(vi &row,vi & col,vvi &mat,vvi & board,vi &call,int idx)
{
    call3++;
    if(idx==call.size())
     {
         display(board);
         return 1;
     }
    int count=0;
    int x=call[idx]/9;
    int y=call[idx]%9;
    for(int num=1;num<=9;num++)
     {
         int mask=1<<num;
         if(!(row[x]&mask)&&!(col[y]&mask)&&!(mat[x/3][y/3]&mask))
          {
              board[x][y]=num;
              row[x]^=mask;
              col[y]^=mask;
              mat[x/3][y/3]^=mask;
              count+=Sudoku_03(row,col,mat,board,call,idx+1);
              board[x][y]=0;
              row[x]^=mask;
              col[y]^=mask;
              mat[x/3][y/3]^=mask;
          }
     }
    return count;
}
bool IsSafeToPWH(int x,int y,vvc & board,string word)
{
    for(int i=0;i<word.size();i++)
     {
         if(!board[x][y+i]=='-' || !board[x][y+i]==word[i])
          {
             return false;
          }
     }
    return true;
}
bool IsSafeToPWV(int x,int y,vvc & board,string word)
{
    for(int i=0;i<word.size();i++)
     {
         if(!board[x+i][y]=='-' || !board[x+i][y]==word[i])
          {
             return false;
          }
     }
    return true;
}
vb PWH(int x,int y,vvc & board,string word)
{
    vb loc(word.size(),false);
    for(int i=0;i<word.size();i++)
     {
        if(board[x][y+i]=='-' || board[x][y+i]==word[i])
         {
            loc[i]=true;
            board[x][y+i]=word[i];
         }
     }
    return loc;
}
vb PWV(int x,int y,vvc & board,string word)
{
    vb loc(word.size(),false);
    for(int i=0;i<word.size();i++)
     {
        if(board[x+i][y]=='-' || board[x+i][y]==word[i])
         {
            loc[i]=true;
            board[x+i][y]=word[i];
         }
     }
    return loc;
}
void UnPWH(int x,int y,vb & loc,vvc &board)
{
    for(int i=0;i<loc.size();i++)
     {
         if(loc[i])
          {
              board[x][y+i]='-';
          }
     }
}
void UnPWV(int x,int y,vb & loc,vvc &board)
{
    for(int i=0;i<loc.size();i++)
     {
         if(loc[i])
          {
              board[x+i][y]='-';
          }
     }
}
// int CrossWord(vvc & board,vc & )
void Sudoku()
{
    vvi board = {{0, 0, 6, 0, 0, 8, 0, 0, 0},
                 {5, 2, 0, 0, 0, 0, 0, 0, 0},
                 {0, 8, 7, 0, 0, 0, 0, 3, 1},
                 {0, 0, 3, 0, 1, 0, 0, 8, 0},
                 {9, 0, 0, 8, 6, 3, 0, 0, 5},
                 {0, 5, 0, 0, 9, 0, 6, 0, 0},
                 {1, 3, 0, 0, 0, 0, 2, 5, 0},
                 {0, 0, 0, 0, 0, 0, 0, 7, 4},
                 {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    vvi board1 = {{8, 4, 0, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 1, 0, 8},
                 {0, 0, 1, 0, 8, 0, 0, 3, 4},
                 {0, 2, 3, 0, 9, 6, 0, 0, 0},
                 {0, 7, 0, 0, 0, 0, 0, 1, 0},
                 {0, 0, 0, 3, 2, 0, 6, 9, 0},
                 {9, 3, 0, 0, 6, 0, 4, 0, 0},
                 {5, 0, 7, 0, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0, 0, 7, 9}};
    vvi board2 = {{4, 1, 0, 6, 0, 0, 0, 0, 0},
                 {0, 0, 9, 0, 0, 0, 7, 0, 6},
                 {6, 5, 0, 2, 9, 3, 0, 0, 0},
                 {2, 7, 0, 8, 1, 4, 0, 0, 0},
                 {0, 0, 4, 9, 0, 5, 6, 0, 0},
                 {0, 0, 0, 3, 7, 6, 0, 4, 1},
                 {0, 0, 0, 4, 6, 1, 0, 9, 0},
                 {9, 0, 3, 0, 0, 0, 4, 0, 0},
                 {0, 0, 0, 0, 0, 9, 0, 6, 2}};
    vi call;
    vi row(9,0);
    vi col(9,0);
    vvi mat(3,vi(3,0));
    for(int i=0;i<9;i++)
     {
         for(int j=0;j<9;j++)
          {
              if(board[i][j]==0)
               {
                   call.push_back((i*9)+j );
               }
              else
               {
                   int mask=1<<board[i][j];
                   row[i]^=mask;
                   col[j]^=mask;
                   mat[i/3][j/3]^=mask;
               }
          }
         
     }
    cout<<Sudoku_01(board2,0);
    // cout<<endl<<call1<<endl; 
    // cout<<Sudoku_02(board,call,0);
    // cout<<endl<<" "<<call2<<endl; 
    // cout<<Sudoku_03(row,col,mat,board2,call,0);
    // cout<<endl<<" "<<call3<<endl;               
}
void queen()
{
    vb col1(4, false);
    vb row1(4, false);
    vb diag1(7, false);
    vb adiag1(7, false);
    int col = 0;
    int diag = 0;
    int adiag = 0;
    cout << Queens2(col, diag, adiag, 0, 4, "") << endl;
}
void solve()
{
    Sudoku();
    // queen();
}
int main(int args, char **argv)
{
    solve();
    return 0;
}