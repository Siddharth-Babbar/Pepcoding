#include<iostream>
#include<vector>
#include<string>

using namespace std;

//=========================Lec_012

string removeHi(string str)
{
    if(str.length()==0)
    return "";
    char ch=str[0];
    if(str.length()>1 && str[0]=='h'&& str[1]=='i')
    return removeHi(str.substr(2));
    else
    return ch+removeHi(str.substr(1));

}
string removeHi2(string str)
{
    if(str.length()==0)
    return "";

    char ch=str[0];
    if(str.length()>2&& str.substr(0,3)=="hit")
    return str.substr(0,3)+removeHi2(str.substr(3));
    else if(str.length()>1&& str.substr(0,2)=="hi")
    return removeHi2(str.substr(2));
    else
    return ch+removeHi2(str.substr(1));
    
}
void removeCon1(string str,string ans)
{
    if(str.length()==0)
    {
     cout<<ans;
     return ;
    }
    if(ans[ans.length()-1]!=str[0])
     {
         ans+=str[0];
         removeCon1(str.substr(1),ans);
     }
     else
     {
        removeCon1(str.substr(1),ans);
     }
     
}
string removeCon2(string str,int vidx)
{
     if(vidx==str.length())
     {
         return string(1,str[vidx-1]);
     }
     if(vidx!=0 && str[vidx-1]!=str[vidx])
      {
          return str[vidx-1]+removeCon2(str,vidx+1);
      }
     else
     return removeCon2(str,vidx+1);
}
vector<string> subseq(string str)
{
    if(str.length()==0)
    {
        vector<string> base;
        base.push_back(" ");
        return base;
    }
    char ch=str[0];
    vector<string> smallans=subseq(str.substr(1));
    vector<string> myans(smallans);
    for(string s:smallans)
    myans.push_back(ch+s);
    return myans;

}
vector<string> MazePathSimple(int sr,int sc,int er,int ec)
{
    if(sr==er&& sc==ec)
     {
         vector<string> base;
         base.push_back("");
         return base;
     }
    vector<string> myans;
    if(sc+1<=ec)
     {
        vector<string> horizontal=MazePathSimple(sr,sc+1,er,ec);
        for(string s:horizontal)
        {
          myans.push_back("h"+s);
        }
     }
    if(sr+1<=er)
     {
        vector<string> vertical=MazePathSimple(sr+1,sc,er,ec);
        for(string s:vertical)
        {
          myans.push_back("v"+s);
        }
     }
     return myans;
}
void mazepath()
{
    vector<string> ans=MazePathSimple(0,0,3,3);
    for(string s:ans)
     {
         cout<<s<<" ";
     }
}
//====================================================================Lec_013
vector<string> MazePathSimple_D(int sr,int sc,int er,int ec)
{
    if(sr==er&& sc==ec)
     {
         vector<string> base;
         base.push_back("");
         return base;
     }
    vector<string> myans;
    if(sc+1<=ec)
     {
        vector<string> horizontal=MazePathSimple_D(sr,sc+1,er,ec);
        for(string s:horizontal)
        {
          myans.push_back("h"+s);
        }
     }
    if(sr+1<=er)
     {
        vector<string> vertical=MazePathSimple_D(sr+1,sc,er,ec);
        for(string s:vertical)
        {
          myans.push_back("v"+s);
        }
     }
     if(sr+1<=er && sc+1<=ec)
      {  
          vector<string> diagonal=MazePathSimple_D(sr+1,sc+1,er,ec);
          for(string s:diagonal)
           {
               myans.push_back("d"+s);
           }
      }
     return myans;
}
int MazePath_D_H(int sr,int sc,int er,int ec)
{
    if(sc==ec && sr==er)
     {
         return 0;
     }
    int hori=0,vert=0,diag=0;
    if(sc+1<=ec)
     {
         hori=MazePath_D_H(sr,sc+1,er,ec);
     }
    if(sr+1<=er)
     {
         vert=MazePath_D_H(sr+1,sc,er,ec);
     }
    if(sc+1<=ec && sr+1<=er)
     {
         diag=MazePath_D_H(sr+1,sc+1,er,ec);
     }
     return (max(hori,max(vert,diag))+1);
}
pair<int,string> MazePath_D_H_P(int sr,int sc,int er,int ec)
{
    if(sr==er && sc==ec)
     {
         pair<int,string> base;
         base.first=0;
         base.second.push_back(' ');
         return base;
     }
    pair<int,string> hori,verti,diag;
    pair<int,string> myans;
    if(sc+1<=ec)
     {
         hori=MazePath_D_H_P(sr,sc+1,er,ec);
          for(char s:hori.second)
          {
              myans.second.push_back('h'+s);
          }
     }
    if(sr+1<=er)
     {
         verti=MazePath_D_H_P(sr+1,sc,er,ec);
         for(char s:verti.second)
         {
             myans.second.push_back('v'+s);
         }
     }
    if(sr+1<=er && sc+1<=ec)
     {
         diag=MazePath_D_H_P(sr+1,sc+1,er,ec);
         for(char s:diag.second)
         {
             myans.second.push_back('d'+s);
         }
     }
    myans.first=(max(hori.first,max(verti.first,diag.first))+1);
    if(myans.first==hori.first+1)
     {
        
     }
    else if(myans.first==verti.first+1)
     {

     }
    else
     {

     }

    return myans;
    

}
vector<string> MazePath_ml(int sr,int sc,int er,int ec)
{
    if(sr==er && sc==ec)
     {
         vector<string> base;
         base.push_back("");
         return base;
     }
    vector<string> myans;
    for(int i=1;sc+i<=ec;i++)
     {
         vector<string> hori=MazePath_ml(sr,sc+i,er,ec);
         for(string s:hori)
          {
             myans.push_back("h"+to_string(i)+s);
          }
     }
    for(int i=1;sr+i<=er;i++)
     {
         vector<string> verti=MazePath_ml(sr+i,sc,er,ec);
         for(string s:verti)
          {
             myans.push_back("v"+to_string(i)+s);
          }

     }
    for(int i=1;sr+1<=er && sc+i<=ec;i++)
     {
         vector<string> diag=MazePath_ml(sr+i,sc+i,er,ec);
         for(string s:diag)
          {
             myans.push_back("d"+to_string(i)+s);
          }
    return myans;
     }
}
void mazepath1()
{
    // vector<string> ans=MazePathSimple_D(0,0,4,7);
    // for(string s:ans)
    //  {
    //      cout<<s<<endl;
    //  }
    cout<<MazePath_D_H(0,0,3,3)<<endl;
    pair<int,string> ans=MazePath_D_H_P(0,0,3,3);
    cout<<ans.first<<endl;
    cout<<ans.second<<endl;
    // vector<string> ans=MazePath_ml(0,0,3,3);
    // for(string s:ans)
    //  {
    //      cout<<s<<endl;
    //  }
}
// ===================================================================Lec_014
bool isSafe(int x,int y,int er,int ec,vector<vector<bool>> & board)
{
    if(x<0||y<0||x>er||y>ec||board[x][y])
     {
         return false;
     }
    return true;
}
bool isSafeRM(int x,int y,int er,int ec,vector<vector<bool>> & board,vector<vector<int>> & bomb)
{
    int i=0,j=0;
    while((i!=bomb.size()-1) && (j!=bomb[1].size()-1))
     {

        if(x<0||y<0||x>er||y>ec||board[x][y]||(x==bomb[i][0]&&y==bomb[0][j]))
         {
            return false;
         }
        i++;
        j++;
            
     }
    return true;
}
vector<vector<int>> direction={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
vector<string> dir={"R","1","U","2","L","3","D","4"};
vector<vector<int>> bomb={{0,0},{1,1}};
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
          if(isSafeRM(x,y,er,ec,board,bomb))
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

}
void mazepath()
{
  
  
}
//==============================================================================================Lec_015
vector<string> words={"_","+-/","abc","def","ghi","jkl","mno","pqrs","tuv","xyz","%*()","#@$"};
vector<string> NokiaKeyPad(string str)
{
    if(str.size()==0)
     {
         vector<string> base;
         base.push_back("");
         return base;
     }
    char ch=str[0];
    string word=words[ch-'0'];
    vector<string> ans;
    vector<string> smallans=NokiaKeyPad(str.substr(1));
    for(string s:smallans)
     {
         for(int i=0;i<word.size();i++)
          {
             ans.push_back(word[i]+s);
          }
     }
    if(str.size()>1 && ch!='0' )
    {
     int num=(ch-'0')*10 + (str[1]-'0');
     if(num<12)
      {
          vector<string> smallans2=NokiaKeyPad(str.substr(2));
          string word2=words[num];
          for(string s:smallans2)
          {
            for(int i=0;i<word2.size();i++)
           {
             ans.push_back(word2[i]+s);
           }
          }
      }
    }
    return ans;
}
vector<string> decoding(string str)
{
    if(str.size()==0)
     {
         vector<string> base;
         base.push_back("");
         return base;
     }
     
    char ch=str[0];
    if(ch=='0')
     {
         return decoding(str.substr(1));
     }
    int num1=ch-'0';
    char chr1=('a'+(num1-1));
    vector<string> myans;
    vector<string> firstRec=decoding(str.substr(1));
    for(string s:firstRec)
     {
         myans.push_back(chr1+s);
     }
    if(str.size()>1)
      {
        int num2=(ch-'0')*10 + (str[1]-'0');
        if(num2<27)
         {
             char chr2=('a'+(num2-1));
             vector<string> secondRec=decoding(str.substr(2));
             for(string s:secondRec)
              {
                myans.push_back(chr2+s);        
              }

         }
      }
    return myans;

}
void basic()
{
// ================================Lec_012
    // mazepath();
    //  for(string s:subseq("abcd"))
    //  cout<<s;
    //removeCon1("aaaaabbbbcccdd","");
    //cout<<removeCon2("aaaaabcd",0);
    vector<string> ans=subseq("abc");
    for(string ele:ans)
     {
         cout<<ele<<endl;
     }
    //cout<<removeHi("hihihihit")<<endl;  
    //cout<<removeHi2("hihihihit")<<endl;
 // ================================Lec_013
     // mazepath1();
 // ================================Lec_014
    // mazepath();
    // floodFill();
    // vector<string> ans=simplePermutation("abc");
    // for(string s:ans)
    //  {
    //      cout<<s<<endl;
    //  }
//  =================================Lec_015
    //    vector<string> myans=NokiaKeyPad("108");
    //    for(string s:myans)
    //     {
    //         cout<<s<<endl;
    //     }
    //   char ch=('a'+1);
    //   cout<<ch;
    //  vector<string> myans=decoding("110");
    //  for(string s:myans)
    //   {
    //       cout<<s<<endl;
    //   }


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
