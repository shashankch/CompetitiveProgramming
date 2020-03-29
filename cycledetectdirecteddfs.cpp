// back edge is the edge which points to one of its ancestor in dfs stack call..

#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

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

    bool iscyclichelper(T node, map<T, bool> &visited, map<T, bool> &instack)
    {

        //processing the current node --visited,instack
        visited[node] = true;
        instack[node] = true;

        // explore the neighbours of the node.

        for (T neighbour : adjList[node])
        {

            // two things can happen
            // the current node is not visited but its further branch is leading to cycle.
            if (!visited[neighbour] && iscyclichelper(neighbour, visited, instack) || instack[neighbour] == true)
            {

                return true;
            }
        }
        // going to pop out the node,instack=false..

        instack[node] = false;
        return false;
    }

    bool iscyclic()
    {

        map<T, bool> visited;
        map<T, bool> instack;
        // to check for cycle in each dfs tree..

        for (auto i : adjList)
        {

            T node = i.first;
            if (!visited[node])
            {

                bool cyclepresent = iscyclichelper(node, visited, instack);
                if (cyclepresent)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{

    Graph<int> g;
    g.addEdge(0, 2, false);
    g.addEdge(0, 1, false);
    g.addEdge(2, 3, false);
    g.addEdge(2, 4, false);
    g.addEdge(3, 0, false);
    g.addEdge(4, 5, false);
    g.addEdge(1, 5, false);

    if (g.iscyclic())
    {
        cout << "cycle present !";
    }
    else
    {
        cout << "cycle not present";
    }

    return 0;
}
