#include<iostream>
#include<vector>

using namespace std;
class Edge
{
    public:
    int v=0;
    int w=0;
    Edge(int v,int w)
     {
         this->v=v;
         this->w=w;
     }
};
int n=7;
vector<vector<Edge*>> graph(7,vector<Edge*>());
void display()
{
    for(int i=0;i<n;i++)
     {
         cout<<i<<":->";
         for(int j=0;j<graph[i].size();j++)
          {
              Edge* ele=graph[i][j];
              cout<<"("<<ele->v<<","<<ele->w<<") ";
          }
        cout<<endl;
     }
}
int minimum=1e8;
string lmin="";
int maximum=-1;
string lmax="";

void addEdge(int u,int v,int w)
{
    graph[u].push_back(new Edge(v,w));
    graph[v].push_back(new Edge(u,w));
}
void ConstructGraph()
{
    addEdge(0,1,10);
    addEdge(0,3,10);
    addEdge(1,2,10);
    addEdge(2,3,40);
    addEdge(3,4,2);
    addEdge(4,5,2);
    addEdge(4,6,3);
    addEdge(5,6,8);
}
void removeEdge(int u,int v)
{
    int i=0;
    for(Edge* e:graph[u])
     {
         if(e->v==v)
          {
              break;
          }
         i++;
     }
    int j=0;
    for(Edge* e:graph[v])
     {
         if(e->v==u)
          {
              break;
          }
         j++;
     }
    graph[u].erase(graph[u].begin()+i);
    graph[v].erase(graph[v].begin()+j);

}
int hasPath(int src,int Des,vector<bool> &visited,string psf)
{
    if(src==Des)
     {
         cout<<psf<<endl;
         return 1;
     }
    int count=0;
    visited[src]=true;
    for(Edge* ele:graph[src])
     {
        if(!visited[ele->v])
         {
            count+=hasPath(ele->v,Des,visited,psf+to_string(ele->v));
         }
     }
    return count;
}
int allPath(int src,int Des,vector<bool> &visited,string psf)
{
    if(src==Des)
     {
         cout<<psf<<endl;
         return 1;
     }
    int count=0;
    visited[src]=true;
    for(Edge* ele:graph[src])
     {
        if(!visited[ele->v])
         {
             count+=allPath(ele->v,Des,visited,psf+to_string(ele->v));
         }
     }
    visited[src]=false;
    return count;
}
int allsolutions(int source,int destination,vector<bool> & visited, int wsf,string psf)
{
    if(source==destination)
     {
         if(wsf>maximum)
          {
              maximum=wsf;
              lmax=psf;
          }
         if(wsf<minimum)
          {
              minimum=wsf;
              lmin=psf;
          }
         return 1; 
     }
    int count=0;
    visited[source]=true;
    for(int i=0;i<graph[source].size();i++)
     {
         Edge* e=graph[source][i];
         if(!visited[e->v])
          {
              count+=allsolutions(e->v,destination,visited,wsf+(e->w),psf+to_string(e->v));
          }
     }
    visited[source]=false;
    return count;
}
void dfs(int source,vector<bool> & visited)
{
    visited[source]=true;
    for(int i=0;i<graph[source].size();i++)
     {
         Edge* e=graph[source][i];
         if(!visited[e->v])
          {
              dfs(e->v,visited);
          }
     }
}
int getConnectedComponent(int source,vector<bool> & visited)
{
    int compo=0;
    for(int i=0;i<graph.size();i++)
     {
         if(!visited[i])
         {
           compo++;
           dfs(i,visited);
         }
     }
    return compo;
}
void solve()
{
   ConstructGraph();
   removeEdge(3,4);
   display();
   cout<<endl;
   vector<bool> visited(7,false);
//    cout<<hasPath(0,6,visited,"0");
//    cout<<allPath(0,6,visited,"");
//    cout<<allsolutions(0,6,visited,0,"0")<<endl;
//    cout<<lmax<<" @"<<maximum<<endl;
//    cout<<lmin<<" @"<<minimum<<endl;
   cout<<"Number of connected component is: "<<getConnectedComponent(0,visited);
   
}
int main(int args,char ** argv)
{
    solve();
    return 0;
}