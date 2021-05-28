#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Edge
{
public:
    int v = 0;
    int w = 0;
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};
class dpair
{
    public:
    int vtx=0;
    int parent=0;
    int wt=0;
    int wsf=0;
    dpair(int vtx,int parent,int wt,int wsf)
     {
         this->vtx=vtx;
         this->parent=parent;
         this->wt=wt;
         this->wsf=wsf;

     }
    bool operator<(dpair const&o) const
     {
         return this->wsf>o.wsf;
     }
};
int n = 7;
vector<vector<Edge *>> Graph(7, vector<Edge *>());
vector<vector<Edge *>> DGraph(7, vector<Edge *>());
vector<int> dShortestPath(n,0);
void display(vector<vector<Edge*>> & Graph)
{
    for (int i = 0; i < n; i++)
    {
        cout << i << ":->";
        for (int j = 0; j < Graph[i].size(); j++)
        {
            Edge *ele = Graph[i][j];
            cout << "(" << ele->v << "," << ele->w << ") ";
        }
        cout << endl;
    }
}
void addEdgeBiDirectional(int u, int v, int w,vector<vector<Edge*>> & Graph)
{
    Graph[u].push_back(new Edge(v, w));
    Graph[v].push_back(new Edge(u,w));
}
void ConstructGraphBiDirectional()
{
    addEdgeBiDirectional(0, 1, 1,Graph);
    addEdgeBiDirectional(0, 3, 2,Graph);
    addEdgeBiDirectional(1, 2, 3,Graph);
    addEdgeBiDirectional(2, 3, 4,Graph);
    addEdgeBiDirectional(3, 4, 5,Graph);
    addEdgeBiDirectional(4, 5, 6,Graph);
    addEdgeBiDirectional(4, 6, 7,Graph);
    addEdgeBiDirectional(5, 6, 8,Graph);
}
void Dijikstra(int src)
{
    priority_queue<dpair> que;
    vector<bool> visited(Graph.size(),false);
    dpair p1(src,-1,0,0);
    que.push(p1);
    while(que.size()!=0)
     {
         dpair rvtx=que.top();
         que.pop();
         if(visited[rvtx.vtx])
          {
              continue;
          }
         if(rvtx.parent!=-1)
          {
            addEdgeBiDirectional(rvtx.parent,rvtx.vtx,rvtx.wt,DGraph);
            dShortestPath[rvtx.vtx]=rvtx.wsf;
          }
         visited[rvtx.vtx]=true;
         for(Edge *e:Graph[rvtx.vtx])
          {
              dpair p(e->v,rvtx.vtx,e->w,rvtx.wsf+e->w);
              que.push(p);
          }
     }
}
void solve()
{
    ConstructGraphBiDirectional();
    Dijikstra(1);
    display(DGraph);
    cout<<endl;
    for(int ele:dShortestPath)
    {
        cout<<ele<<" ";
    }
}
int main(int args, char **argv)
{
    solve();
    return 0;
}