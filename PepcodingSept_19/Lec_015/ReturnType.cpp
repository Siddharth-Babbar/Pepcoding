#include<iostream>
#include<vector>
#include<string>

using namespace std;

//=========================
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
void mazepath()
{
  
  
}
void basic()
{
//    vector<string> myans=NokiaKeyPad("108");
//    for(string s:myans)
//     {
//         cout<<s<<endl;
//     }
//   char ch=('a'+1);
//   cout<<ch;
     vector<string> myans=decoding("110");
     for(string s:myans)
      {
          cout<<s<<endl;
      }

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
