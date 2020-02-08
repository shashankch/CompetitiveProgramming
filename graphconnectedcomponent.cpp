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
        int component=1;
        dfshelper(src, visited);
        cout<<endl;

        for(auto i:adjList){
            T city=i.first;
            if(!visited[city]){
                dfshelper(city,visited);
                component++;
            }
        }
        
        cout<<endl<<"The current graph had "<<component<<" components"<<endl;
    }
};

int main(int argc, char const *argv[])
{

    Graph<string> g;

    g.addEdge("amritsar", "jaipur");
    g.addEdge("amritsar", "delhi");
    g.addEdge("delhi", "jaipur");
    g.addEdge("mumbai", "jaipur");
    g.addEdge("mumbai", "bhopal");
    g.addEdge("delhi", "bhopal");
    g.addEdge("mumbai", "bangalore");
    g.addEdge("agra", "delhi");
    g.addEdge("andaman", "nicobar");
    g.dfs("amritsar");

    return 0;
}
