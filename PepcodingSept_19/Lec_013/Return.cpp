#include<iostream>
#include<vector>
#include<string>

using namespace std;

//=========================

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
    // if(myans.first==hori.first+1)
    //  {
    //     myans.second.push_back('h');
    //  }
    // else if(myans.first==verti.first+1)
    //  {
    //    myans.second.push_back('v');
    //  }
    // else
    //  {
    //    myans.second.push_back('d');
    //  }

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
void mazepath()
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
void basic()
{
    mazepath();

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
