#include <iostream>
#include <list>
#define inf 1e9
using namespace std;

class Graph
{
public:
    int v;
    list<pair<int, int>> *adj;
    Graph(int v)
    {
        this->v = v;
        adj = new list<pair<int, int>>[v];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int findMinVertex(int *weight, bool *visited, int v)
    {
        int minVertex = -1;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i] and (minVertex == -1 or weight[i] < weight[minVertex]))
            {
                minVertex = i;
            }
        }
        return minVertex;
    }

    void Prims()
    {

        bool *visited = new bool[v];
        int *parent = new int[v];
        int *weight = new int[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
            weight[i] = inf;
        }
        parent[0] = -1;
        weight[0] = 0;
        for (int i = 0; i < v; i++)
        {
            int minvertex = findMinVertex(weight, visited, v);
            visited[minvertex] = true;
            for (auto neighbour : adj[minvertex])
            {

                if (!visited[neighbour.first])
                {
                    if (weight[neighbour.first] > neighbour.second)
                    {
                        // if the wt of the vertex in our mapping is greater than wt at particular edge or not..
                        parent[neighbour.first] = minvertex;
                        weight[neighbour.first] = neighbour.second;
                    }
                }
            }
        }
        for (int i = 1; i < v; i++)
        {
            cout << i << "-->" << parent[i] << "weight = " << weight[i] << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.Prims();
    return 0;
}

/*
7
8
0 3 4
0 1 6
1 2 5
3 2 7
3 4 2
4 5 4
5 6 1
4 6 3

*/