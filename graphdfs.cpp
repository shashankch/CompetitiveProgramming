#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

// bfs : iterative queue FIFO
template <typename T>
class Graph
{

    map<T, list<T>> adjList;

public:
    Graph()
    {
    }
    void addEdge(T u, T v, bool bidir = true)
    {

        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void print()
    {

        //iterate over the map
        for (auto i : adjList)
        {

            cout << i.first << "-->";

            // i.second is LL
            for (T entry : i.second)
            {
                cout << entry << ",";
            }
            cout << endl;
        }
    }

    void dfshelper(T node, map<T, bool> &visited)
    {

        // whenever come to a node mark it visited.
        visited[node] = true;
        cout << node << " ";

        // try to find out a node which is neighbour of current node and unvisited.
        for (T neighbour : adjList[node])
        {

            if (!visited[neighbour])
            {
                dfshelper(neighbour, visited);
            }
        }
    }
    void dfs(T src)
    {

        map<T, bool> visited;

        dfshelper(src, visited);
    }
};

int main(int argc, char const *argv[])
{

    Graph<int> g2;

    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(0, 4);
    g2.addEdge(2, 4);
    g2.addEdge(2, 3);
    g2.addEdge(3, 5);
    g2.addEdge(3, 4);
    g2.dfs(0);

    return 0;
}
