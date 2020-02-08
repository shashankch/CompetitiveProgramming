#include <iostream>
#include<climits>
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

    void ssp(T src)
    {

        queue<T> q;
        map<T, T> dist;
        map<T,T>parent;

        for(auto i:adjList){
            dist[i.first]=INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src]=src;

        while (!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();

            // for the neighbours of the current node,find out the node which are not visited;
            for (int neighbour : adjList[node])
            {
                if (dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] =dist[node]+1;
                    parent[neighbour]=node; 

                }
            }
        }

    // print the distance to all the nodes
    for(auto i:adjList){
        T node=i.first;
        cout<<"Dist of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
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

    g2.ssp(0);
    return 0;
}
