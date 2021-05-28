#include<iostream>
#include<queue>
#include<vector>

using namespace std;
#define pii pair<int,int> 
#define piii pair<int,pii> 
int n=7;

//DSU=============================================================

void merge(int p1,int p2,vector <int>& parent,vector<int> & size)
{
    if(size[p1]<size[p2])
     {
         parent[p1]=p2;
         size[p2]+=size[p1];
     }
    else
     {
        parent[p2]=p1;
        size[p1]+=size[p2];
     }
    
}
int findParent(int vtx,vector<int> &parent)
{
   if(parent[vtx]==vtx)
    {
        return vtx;
    }
   parent[vtx]=findParent(parent[vtx],parent);
   return parent[vtx];
}
void DSU()
{
    vector<int> parent(n,0);
    vector<int> size(n,1);
    int cycle=0;
    for(int i=0;i<n;i++)
     {
         parent[i]=i;
     }
    vector<vector<int>> edges={{0,1},{0,3},{1,2},{2,3},{3,4},{4,5},{4,6},{5,6}};
    for(vector<int> ele:edges)
     {
         int p1=findParent(ele[0],parent);
         int p2=findParent(ele[1],parent);
         if(p1==p2)
          {
              cycle++;
              cout<<"("<<ele[0]<<" ,"<<ele[1]<<")";
              continue;
          }
         merge(p1,p2,parent,size);

     }
    cout<<cycle;
}
void Kruskal(vector<piii> & arr,vector<int> & parent,vector<int> &size,int n)
{
    vector<vector<pii>>  newGraph(n,vector<pii>());
    for(int i=0;i<arr.size();i++)
     {
        piii rp=arr[i];
        int p1=findParent(rp.second.first,parent);
        int p2=findParent(rp.second.second,parent);
        if(p1!=p2)
         {
             merge(p1,p2,parent,size);
             newGraph[rp.second.first].push_back({rp.second.second,rp.first});
             newGraph[rp.second.second].push_back({rp.second.first,rp.first});
         }

     }
}
void Kruskal_()
{
  int n=7;
  vector<piii> arr;
  arr.push_back({10,{0,3}});   
  arr.push_back({16,{0,1}});
  arr.push_back({10,{1,2}});
  arr.push_back({40,{2,3}});
  arr.push_back({2,{3,4}});
  arr.push_back({2,{4,5}});
  arr.push_back({3,{4,6}});
  arr.push_back({8,{5,6}});
  sort(arr.begin(),arr.end(),[](piii a,piii b)
   {
       return a.first<b.first;
   });
  
}
// void MinTimeFrame(vector<vector<int>> &orange)
// {
//     queue<piii> roranges;
//     int rsize=orange.size();
//     int csize=orange[0].size();
//     for(int i=0;i<rsize;i++)
//      {
//          for(int j=0;j<csize;j++)
//           {
//               if(orange[i][j]==2)
//                {
//                    roranges.push({(i*csize+j),0});
//                }
//           }
//      }
//     while(roranges.size()!=0)
//      {
//          int size=roranges.size();
//          while(size-- >0)
//           {
//               pair<int,int> r=roranges.front();
//               roranges.pop();
//               int row=r.first/csize;
//               int col=r.first%csize;
//               for()



//           }
//      }
// }
// void mintimeFrame()
// {
//     vector<vector<int>> orange={{2,0,1},
//                                 {1,0,2},
//                                 {2,0,0}};
// }

void solve()
{
   DSU();
}
int main(int args,char** argv)
{
    solve();
    return 0;
}