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
void ConstructGraphDirectional()
{
    addEdgeDirectional(0, 1, 2,DirectionalGraph);
    addEdgeDirectional(0, 3, 2,DirectionalGraph);
    addEdgeDirectional(1, 2, 2,DirectionalGraph);
    addEdgeDirectional(2, 3, 2,DirectionalGraph);
    addEdgeDirectional(3, 4, 2,DirectionalGraph);
    addEdgeDirectional(4, 5, 2,DirectionalGraph);
    addEdgeDirectional(4, 6, 2,DirectionalGraph);
    addEdgeDirectional(5, 6, 2,DirectionalGraph);
}