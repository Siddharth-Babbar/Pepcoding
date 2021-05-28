#include<iostream>
#include<vector>

using namespace std;
int subseq(string s,string ans)
{
    if(s.size()==0)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    count+=subseq(s.substr(1),ans);
    count+=subseq(s.substr(1),ans+s[0]);
    return count;
}
string words[]={".:;","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz","@$&","-_%"};
int Keypad(string num,string ans)
{
    if(num.size()==0)
     {
         cout<<ans<<endl;
         return 1;
     }
    int idx1=num[0]-'0';
    int idx2=idx1*10+(num[1]-'0');
    string word=words[idx1];
    int count=0;
    for(int i=0;i<word.size();i++)
      {
          count+=Keypad(num.substr(1),ans+word[i]);
      }
    if(num.size()>=2)
    {
     if(idx2>=10 && idx2<=11)
     {
      word=words[idx2];
      for(int i=0;i<word.size();i++)
       {
           count+=Keypad(num.substr(2),ans+word[i]);
       }
     }
    }
    
     return count;
}
int permutation1(string s,string ans)
{
    if(s.size()==0)
     {
         cout<<ans<<endl;
         return 1;
     }
     int count =0;
     for(int i=0;i<s.size();i++)
      {
          string str=s.substr(0,i)+s.substr(i+1);
          count+=permutation1(str,ans+s[i]);
      }
      return count;
}
int permutation2(string s,string ans)
{
    if(s.size()==0)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    vector<bool> vis(26,false);
    for(int i=0;i<s.size();i++)
     {
         if(!vis[s[i]-'a'])
          {
              vis[s[i]-'a']=true;
              string str=s.substr(0,i)+s.substr(i+1);
              count+=permutation2(str,ans+s[i]);
          }
     }
     return count;
}
int permutation3(string s,string ans)
{
    if(s.size()==0)
     {
         cout<<ans<<endl;
         return 1;
     }
    int count=0;
    int vis=0;
    for(int i=0;i<s.size();i++)
     {
         int mask=(1<<(s[i]-'a'));
         if(((vis&mask)==0))
          {
              vis|=mask;
              string str=s.substr(0,i)+s.substr(i+1);
              count+=permutation3(str,ans+s[i]);
          }
     }
     return count;
}
int decoder(string s,string ans)
{
    if(s.size()==0)
     {
         cout<<ans<<endl;
         return 1;
     }
     int count=0;
     int idx1=s[0]-'0';
     int idx2=idx1*10 + (s[1]-'0');
}
void basicQues()
{
//    cout<<subseq("abc","");
    //   cout<<Keypad("10110","");
    //  cout<<permutation1("abc","");
    //  cout<<permutation2("aab","");
     cout<<permutation3("aab","");
}
void solve()
{
  basicQues();
}
int main(int args,char** argv)
{
    solve();
    return 0;
}