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
int n = 7;
vector<vector<Edge *>> graph(7, vector<Edge *>());
vector<vector<Edge *>> DirectionalGraph(7, vector<Edge *>());
vector<vector<Edge *>> InverseDirectionalGraph(7, vector<Edge *>());
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
void displayDirectional()
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << ":->";
        for (int j = 0; j < DirectionalGraph[i].size(); j++)
        {
            Edge *ele = DirectionalGraph[i][j];
            cout << "(" << ele->v << "," << ele->w << ") ";
        }
        cout << endl;
    }
}
void addEdgeDirectional(int u, int v, int w,vector<vector<Edge*>> & Graph)
{
    Graph[u].push_back(new Edge(v, w));
}
void addEdgeBiDirectional(int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}
void ConstructGraphDirectional()
{
    // addEdgeDirectional(0, 1, 10);
    // addEdgeDirectional(0, 2, 10);
    // addEdgeDirectional(1, 5, 10);
    // addEdgeDirectional(5, 6, 10);
    // addEdgeDirectional(6, 8, 10);
    // addEdgeDirectional(7, 6, 10);
    // addEdgeDirectional(2, 7, 10);
    // addEdgeDirectional(4, 7, 10);
    // addEdgeDirectional(3, 2, 10);
    // addEdgeDirectional(3, 4, 10);
    // addEdgeDirectional(7, 9, 10);
    // addEdgeDirectional(9, 12, 10);
    // addEdgeDirectional(9, 10, 10);
    // addEdgeDirectional(10, 11, 10);
    // addEdgeDirectional(11, 12, 10);
    // addEdgeDirectional(0, 6, 10,DirectionalGraph);
    // addEdgeDirectional(0, 4, 10,DirectionalGraph);
    // addEdgeDirectional(6, 5, 10,DirectionalGraph);
    // addEdgeDirectional(5, 6, 10,DirectionalGraph);
    // addEdgeDirectional(4, 5, 10,DirectionalGraph);
    // addEdgeDirectional(7, 4, 10,DirectionalGraph);
    // addEdgeDirectional(4, 3, 10,DirectionalGraph);
    // addEdgeDirectional(3, 2, 10,DirectionalGraph);
    // addEdgeDirectional(2, 0, 10,DirectionalGraph);
    // addEdgeDirectional(1, 0, 10,DirectionalGraph);
    // addEdgeDirectional(9, 1, 10,DirectionalGraph);
    // addEdgeDirectional(8, 1, 10,DirectionalGraph);
    // addEdgeDirectional(8, 9, 10,DirectionalGraph);
    // addEdgeDirectional(8, 2, 10,DirectionalGraph);
    // addEdgeDirectional(8, 7, 10,DirectionalGraph);
    // addEdgeDirectional(0, 1, 10,DirectionalGraph);
    // addEdgeDirectional(0, 3, 10,DirectionalGraph);
    // addEdgeDirectional(1, 2, 10,DirectionalGraph);
    // addEdgeDirectional(2, 3, 40,DirectionalGraph);
    // addEdgeDirectional(3, 4, 2,DirectionalGraph);
    // addEdgeDirectional(4, 5, 2,DirectionalGraph);
    // addEdgeDirectional(4, 6, 3,DirectionalGraph);
    // addEdgeDirectional(5, 6, 8,DirectionalGraph);
    // addEdgeDirectional(0, 2, 10,DirectionalGraph);
    // addEdgeDirectional(2, 1, 10,DirectionalGraph);
    // addEdgeDirectional(1, 0, 10,DirectionalGraph);
    // addEdgeDirectional(0, 3, 40,DirectionalGraph);
    // addEdgeDirectional(3, 4, 2,DirectionalGraph);
    addEdgeDirectional(0, 1, 2,DirectionalGraph);
    addEdgeDirectional(0, 3, 2,DirectionalGraph);
    addEdgeDirectional(1, 2, 2,DirectionalGraph);
    addEdgeDirectional(2, 3, 2,DirectionalGraph);
    addEdgeDirectional(3, 4, 2,DirectionalGraph);
    addEdgeDirectional(4, 5, 2,DirectionalGraph);
    addEdgeDirectional(4, 6, 2,DirectionalGraph);
    addEdgeDirectional(5, 6, 2,DirectionalGraph);
    




}
void ConstructGraphBiDirectional()
{
    addEdgeBiDirectional(0, 1, 10);
    addEdgeBiDirectional(0, 3, 10);
    addEdgeBiDirectional(1, 2, 10);
    addEdgeBiDirectional(2, 3, 40);
    addEdgeBiDirectional(3, 4, 2);
    addEdgeBiDirectional(4, 5, 2);
    addEdgeBiDirectional(4, 6, 3);
    addEdgeBiDirectional(5, 6, 8);
    // addEdgeBiDirectional(2,5,10);
    // addEdgeBiDirectional(0,6,10);
}
bool topologicalSort_(int src, vector<bool> &visited, vector<bool> &cycleDetection, vector<int> &stack)
{
    visited[src] = true;
    cycleDetection[src] = true;
    bool flag = false;
    for (Edge *e : DirectionalGraph[src])
    {
        if (!visited[e->v])
        {
            flag = flag || topologicalSort_(e->v, visited, cycleDetection, stack);
        }
        else if (cycleDetection[e->v])
        {
            return true;
            ;
        }
    }
    stack.push_back(src);
    cycleDetection[src] = false;
    return flag;
}
void topologicalSort()
{
    vector<bool> visited(DirectionalGraph.size(), false);
    vector<int> stack;
    vector<bool> cycleDetection(DirectionalGraph.size(), false);
    bool res;
    for (int i = 0; i < DirectionalGraph.size(); i++)
    {
        if (!visited[i])
        {
            res = topologicalSort_(i, visited, cycleDetection, stack);
        }
    }
    if (!res)
    {
        while (stack.size() != 0)
        {
            cout << stack.back() << " ";
            stack.pop_back();
        }
    }
    else
    {
        cout << "no topological sort";
    }
}
void kahnAlgorithm()
{
    vector<int> CountIndegree(DirectionalGraph.size(),0);
    for(int i=0;i<DirectionalGraph.size();i++)
     {
        for(Edge* e:DirectionalGraph[i])
         {
             CountIndegree[e->v]++;
         }
     }
    queue<int> ZeroIndegree;
    vector<int> TopologicalSort;
    for (int i = 0; i < CountIndegree.size(); i++)
    {
        if (CountIndegree[i] == 0)
         {
            ZeroIndegree.push(i);
         }
    }
    while (ZeroIndegree.size() != 0)
    {
        int rvtx = ZeroIndegree.front();
        ZeroIndegree.pop();
        TopologicalSort.push_back(rvtx);
        for(Edge* e:DirectionalGraph[rvtx])
         {
             CountIndegree[e->v]--;
             if(CountIndegree[e->v]==0)
              {
                  ZeroIndegree.push(e->v);
              }
         }
        
    }   
    if(TopologicalSort.size()!=DirectionalGraph.size())
     {
         cout<<"Cycle"<<endl;
     }
    else
     {
        for(int i=0;i<TopologicalSort.size();i++)
         {
             cout<<TopologicalSort[i]<<" ";
         }
     }
     
}
void Inverse(vector<vector<Edge*>> & Graph)
{
  for(int u=0;u<Graph.size();u++)
   {
       for(Edge* ele:Graph[u])
        {
            addEdgeDirectional(ele->v,u,ele->w,InverseDirectionalGraph);
        }
   }
}
void DfsKR_(int src,vector<bool> & visited)
{
    visited[src]=true;
    for(Edge* e:InverseDirectionalGraph[src])
     {
         if(!visited[e->v])
         {
           DfsKR_(e->v,visited);
         }
     }
}
void DfsKR(vector<int> & stack)
{
    vector<bool> visited(stack.size(),false);
    vector<bool> ansStack;
    int count=0;

    while(stack.size()!=0)
     {
       int rvtx=stack.back();
       stack.pop_back();
       if(!visited[rvtx])
        {
            // cout<<count;
            DfsKR_(rvtx,visited);
            count++;
        }
        
     }
    cout<<count;
}
void TopologicalSortKR_(int src,vector<bool> & visited,vector<int> & stack)
{
    visited[src]=true;
    for(Edge* e:DirectionalGraph[src])
     {
         if(!visited[e->v])
          {
              TopologicalSortKR_(e->v,visited,stack);
          }
     }
    stack.push_back(src);

}
vector<int> TopologicalSortKR()
{
    vector<bool> visited(DirectionalGraph.size(),false);
    vector<int> stack;
    for(int i=0;i<DirectionalGraph.size();i++)
     {
       if(!visited[i])
        {
            TopologicalSortKR_(i,visited,stack);
        }
     } 
    return stack;
    
}
void Kosaraju()
{
    vector<int> stack;
    stack=TopologicalSortKR();
    for(int ele:stack)
     {
         cout<<ele<<" ";
     }
    Inverse(DirectionalGraph);
    display(InverseDirectionalGraph);
    DfsKR(stack);
}
void solve()
{
    ConstructGraphDirectional();
    // displayDirectional();
    // topologicalSort();
    // kahnAlgorithm();
    // Inverse(DirectionalGraph);
    // display(DirectionalGraph);
    // display(InverseDirectionalGraph);
    Kosaraju();
}
int main(int args, char **argv)
{
    solve();
    return 0;
}
