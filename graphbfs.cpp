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

    void bfs(T src)
    {

        queue<T> q;
        map<T, bool> visited;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();

            // for the neighbours of the current node,find out the node which are not visited;
            for (int neighbour : adjList[node])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
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

    g2.bfs(0);
    return 0;
}
