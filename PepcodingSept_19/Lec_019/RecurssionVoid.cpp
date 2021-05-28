#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool IsSafeToPlaceQueen(vector<vector<bool>> &board, int r, int c)
{
    vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
    for (int i = 0; i < dir.size(); i++)
    {
        for (int radius = 1; radius < max(board.size(), board[0].size()); radius++)
        {
            int x = r + radius * dir[i][0];
            int y = c + radius * dir[i][1];
            if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
            {
                break;
            }
            if (board[x][y])
            {
                return false;
            }
        }
    }
    return true;
}
bool ShadowMethIsSafeToPlaceQueen(vector<bool> &RowCheck, vector<bool> &ColCheck, vector<bool> &PriDiaCheck, vector<bool> &SecDiaCheck, int x, int y)
{

    for (int i = 0; i < RowCheck.size(); i++)
    {
        if (RowCheck[x])
        {
            return false;
        }
    }
    for (int i = 0; i < ColCheck.size(); i++)
    {
        if (ColCheck[y])
        {
            return false;
        }
    }
    for (int i = 0; i < PriDiaCheck.size(); i++)
    {
        if (PriDiaCheck[x - y + max(RowCheck.size(), ColCheck.size()) - 1])
        {
            return false;
        }
    }
    for (int i = 0; i < SecDiaCheck.size(); i++)
    {
        if (SecDiaCheck[x + y])
        {
            return false;
        }
    }
    return true;
}
int ActualNQueenPermu(vector<vector<bool>> &board, int lqpl, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < board.size() * board[0].size(); i++)
    {
        int x = i / board[0].size();
        int y = i % board[0].size();
        if (IsSafeToPlaceQueen(board, x, y) && !board[x][y])
        {
            board[x][y] = true;
            count += ActualNQueenPermu(board, i + 1, qpsf + 1, tnq, ans + "(" + to_string(x) + "," + to_string(y) + ") ");
            board[x][y] = false;
        }
    }
    return count;
}
int ActualNQueenCombi(vector<vector<bool>> &board, int lqpl, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
        // for(vector<bool> b:board)
        //  {
        //      for(bool ele:b)
        //       {
        //           cout<<ele<<" ";
        //       }
        //       cout<<endl;
        //  }
        // return 1;
    }
    int count = 0;
    for (int i = lqpl; i < board.size() * board[0].size(); i++)
    {
        int x = i / board[0].size();
        int y = i % board[0].size();
        if (IsSafeToPlaceQueen(board, x, y))
        {
            board[x][y] = true;
            count += ActualNQueenCombi(board, i + 1, qpsf + 1, tnq, ans + "(" + to_string(x) + "," + to_string(y) + ") ");
            board[x][y] = false;
        }
    }
    return count;
}
int ShadowMethActualNQueenCombi(vector<bool> &RowCheck, vector<bool> &ColCheck, vector<bool> &PriDiaCheck, vector<bool> &SecDiaCheck, int lqpl, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = lqpl; i < RowCheck.size() * ColCheck.size(); i++)
    {
        int x = i / ColCheck.size();
        int y = i % ColCheck.size();
        if (ShadowMethIsSafeToPlaceQueen(RowCheck, ColCheck, PriDiaCheck, SecDiaCheck, x, y))
        {

            RowCheck[x] = true;
            ColCheck[y] = true;
            PriDiaCheck[x - y + max(RowCheck.size(), ColCheck.size()) - 1] = true;
            SecDiaCheck[x + y] = true;
            count += ShadowMethActualNQueenCombi(RowCheck, ColCheck, PriDiaCheck, SecDiaCheck, i + 1, qpsf + 1, tnq, ans + "(" + to_string(x) + "," + to_string(y) + ") ");
            RowCheck[x] = false;
            ColCheck[y] = false;
            PriDiaCheck[x - y + max(RowCheck.size(), ColCheck.size()) - 1] = false;
            SecDiaCheck[x + y] = false;
        }
    }
    return count;
}
int ActualNQueen1(vector<bool> &RowCheck, vector<bool> &ColCheck, vector<bool> &PriDiaCheck, vector<bool> &SecDiaCheck, int row,int qpsf, int tnq, string ans)
{
    if (qpsf == tnq || row == RowCheck.size())
    {
        if (qpsf == tnq)
        {
            cout << ans << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int count = 0;
    for (int i = 0; i < ColCheck.size(); i++)
    {
        int x = row;
        int y = i;
        if (ShadowMethIsSafeToPlaceQueen(RowCheck, ColCheck, PriDiaCheck, SecDiaCheck, x, y))
        {
            ColCheck[y] = true;
            PriDiaCheck[x - y + ColCheck.size() - 1] = true;
            SecDiaCheck[x + y] = true;
            count += ActualNQueen1(RowCheck, ColCheck, PriDiaCheck, SecDiaCheck, row + 1, qpsf + 1, tnq, ans + "(" + to_string(x) + "," + to_string(y) + ")");
            ColCheck[y] = false;
            PriDiaCheck[x - y + max(RowCheck.size(), ColCheck.size()) - 1] = false;
            SecDiaCheck[x + y] = false;
        }
        
    }
    return count;
}
void nqueen()
{
    vector<vector<bool>> board(4, vector<bool>(4, false));
    // cout<<ActualNQueenCombi(board,0,0,4,"");
    // cout<<ActualNQueenPermu(board,0,0,4,"");
    vector<bool> RowCheck(board.size(), false);
    vector<bool> ColCheck(board[0].size(), false);
    vector<bool> PriDiaCheck((board.size() + max(board.size(), board[0].size()) - 1), false);
    vector<bool> SecDiaCheck((board.size() + board[0].size() - 1), false);
    //cout <<ShadowMethActualNQueenCombi(RowCheck,ColCheck,PriDiaCheck,SecDiaCheck,0,0,4,"");
    cout << ActualNQueen1(RowCheck, ColCheck, PriDiaCheck, SecDiaCheck, 0, 0, 4, "");
}
void solve()
{
    nqueen();
}
int main(int args, char **argv)
{
    solve();
    return 0;
}