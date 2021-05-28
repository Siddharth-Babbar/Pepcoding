#include<iostream>
#include<vector>
#include<queue>

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
vector<vector<Edge*>> DirectionalGraph(4,vector<Edge*>());
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
void displayDirectional()
{
    for(int i=0;i<4;i++)
     {
         cout<<i<<":->";
         for(int j=0;j<DirectionalGraph[i].size();j++)
          {
              Edge* ele=DirectionalGraph[i][j];
              cout<<"("<<ele->v<<","<<ele->w<<") ";
          }
         cout<<endl;
     }
}
void addEdgeDirectional(int u,int v,int w)
{
    DirectionalGraph[u].push_back(new Edge(v,w));
}
void addEdgeBiDirectional(int u,int v,int w)
{
    graph[u].push_back(new Edge(v,w));
    graph[v].push_back(new Edge(u,w));
}
void ConstructGraphDirectional()
{
    // addEdgeDirectional(0,1,10);
    // addEdgeDirectional(0,4,10);
    // addEdgeDirectional(1,2,10);
    // addEdgeDirectional(2,3,10);
    // addEdgeDirectional(7,4,10);
    // addEdgeDirectional(7,6,10);
    // addEdgeDirectional(6,5,10);
    // addEdgeDirectional(5,3,10);
    addEdgeDirectional(0,1,10);
    addEdgeDirectional(1,2,10);
    addEdgeDirectional(2,3,10);
    addEdgeDirectional(3,0,10);
}
void ConstructGraphBiDirectional()
{
    addEdgeBiDirectional(0,1,10);
    addEdgeBiDirectional(0,3,10);
    addEdgeBiDirectional(1,2,10);
    addEdgeBiDirectional(2,3,40);
    addEdgeBiDirectional(3,4,2);
    addEdgeBiDirectional(4,5,2);
    addEdgeBiDirectional(4,6,3);
    addEdgeBiDirectional(5,6,8);
    // addEdgeBiDirectional(2,5,10);
    // addEdgeBiDirectional(0,6,10);
}
int IsHameltonian(int vix,int osrc,int EdgeCount,vector<bool> & visited,string ans)
{
    if(EdgeCount==graph.size()-1)
     {
        bool flag=false;
        for(Edge* e:graph[vix])
         {
             if((e->v)==osrc)
              {
                  cout<<"cycle:"<<ans+to_string(vix)<<endl;
                  flag=true;
              }
         }
        if(!flag)
         {
             cout<<"path:"<<ans+to_string(vix)<<endl;
         }
        return 1;
     }
    int count=0;
    visited[vix]=true;
    for(Edge * e:graph[vix])
     {
        if(!visited[e->v])
         {
             count+=IsHameltonian(e->v,osrc,EdgeCount+1,visited,ans+to_string(vix)+" ");
         }
     }
    visited[vix]=false;
    return count;     

}
bool IsBiParted(int i,vector<int> & visited)
{
    queue<pair<int,int>> que;
    pair<int,int> a(i,0);
    que.push(a);
    bool flag=true;
    while(que.size()!=0)
     {
         pair<int,int> rvtx=que.front();
         que.pop();
         if(visited[rvtx.first]!=-1)
         {
           if(rvtx.second!=visited[rvtx.first])
            {
                cout<<"conflict"<<endl;
                flag=false;
            }
           continue;
         }
         visited[rvtx.first]=rvtx.second;
         for(Edge* e:graph[rvtx.first])
          {
              if(visited[e->v]==-1)
               {
                   pair<int,int> ele;
                   ele.first=e->v;
                   ele.second=(rvtx.second+1)%2;
                   que.push(ele);
               }
          }
     }
    return flag;

}
void BiParted(int src)
{
    vector<int> visited(graph.size(),-1);
    int count=0;
    for(int i=0;i<graph.size();i++)
     {
         if(visited[i]==-1)
          {
            
            cout<<count<<" "<<(boolalpha)<<IsBiParted(i,visited)<<endl;
            count++;
             
          }
     }
}
bool topologicalSort_(int vix,vector<bool> & visited,vector<int> & stack,vector<bool> & check)
{
   check[vix]=true;
   visited[vix]=true;
   for(Edge* e:DirectionalGraph[vix])
    {
        if(check[e->v])
         {
             cout<<"wrong answer"<<endl;
             return false;
         }
        if(!visited[e->v])
         {
            topologicalSort_(e->v,visited,stack,check);
         }
    }
    stack.push_back(vix);
    return true;
}
void topologicalSort()
{
    vector<bool> visited(DirectionalGraph.size(),false);
    vector<int> stack;
    bool flag=true;
    for(int i=0;i<DirectionalGraph.size();i++)
     {
         if(!visited[i])
          {
              vector<bool> check(DirectionalGraph.size(),false);
              flag=topologicalSort_(i,visited,stack,check);
          }
     }
     if(flag)
     { 
      while(stack.size()!=0)
       {
           cout<<stack.back()<<" ";
           stack.pop_back();
       }
     }

}
void solve()
{
    // ConstructGraphBiDirectional();
    // display();
   ConstructGraphDirectional();
   displayDirectional();
//    vector<bool> visited(n,false);
//    cout<<IsHameltonian(0,0,0,visited,"");
//    BiParted(0);
   topologicalSort();
}
int main(int args,char** argv)
{
    solve();
    return 0;
}