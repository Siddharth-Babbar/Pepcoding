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
void bfs(int src)
{
    
    queue<int> que;
    que.push(src);
    que.push(-1);
    int cycle=0;
    int level=0;
    vector<bool> visited(7,false);
    int des=4;
    while(que.size()!=1)
     {
         int rvtx=que.front();
         que.pop();
         
          if(rvtx==-1)
           {
              level++;
              que.push(-1);
              continue;
           }
               
         if(visited[rvtx])
          {
              cout<<"cycle :"<<++cycle<<"@ level:"<<level<<endl;
              continue;
          }
         if(rvtx==des)
          {
              cout<<"goal: "<<level<<endl;
          }
         visited[rvtx]=true;
         for(Edge* e:graph[rvtx])
          {
              if(!visited[e->v])
               {
                   que.push(e->v);
                   
               }                   
                  
          }
     }

}
void bfs2(int source)
{
    queue<int> que;
    que.push(source);
    int level=0;
    int cycle=0;
    vector<bool> visited(n,false);
    int isdest=false;
    int dest=4;
    while(que.size()!=0)
     {
         int size=que.size();
         while(size-- >0)
          {
              int rvtx=que.front();
              que.pop();
              if(visited[rvtx])
               {
                   cout<<"cycle:"<<++cycle<<"@ level:"<<level<<endl;
                   continue;
               }
              if(rvtx==dest && !isdest)
               {
                  cout<<"goal:"<<level<<endl;
                  isdest=true;
               }
              visited[rvtx]=true;
              for(Edge* e:graph[rvtx] )
               {
                   if(!visited[e->v])
                    {
                       que.push(e->v);
                    }
               }
              
          }
         level++;
     }
}
void bfs3(int src)
{
    queue<pair<int,int>> que;
    pair<int,int> ele;
    ele.first=src;
    ele.second=0;   
    que.push(ele);
    int cycle=0;
    vector<bool> visited(n,false);
    int isDest=false;
    int dest=4;
    while(que.size()!=0)
     {
        pair<int,int> rvtx=que.front();
        que.pop();
        if(visited[rvtx.first])
         {
            cout<<"cycle:"<<++cycle<<"@ level:"<<rvtx.second<<endl;
            continue;
         }
        if(rvtx.first==dest && !isDest)
         {
            cout<<"goal at level:"<<rvtx.second<<endl;
            isDest=true;
         }
        visited[rvtx.first]=true;
        for(Edge* e:graph[rvtx.first])
         {
            if(!visited[e->v])
             {
                pair<int,int> ef;
                ef.first=e->v;
                ef.second=rvtx.second +1;
                que.push(ef);
             }
         }
     }


}
void solve()
{
    ConstructGraph();
    display();
    vector<bool> visited(7,false);
    bfs(1);
    cout<<endl;
    bfs2(1);
    cout<<endl;
    bfs3(1);
}
int main(int args,char** argv)
{
    solve();
    return 0;
}