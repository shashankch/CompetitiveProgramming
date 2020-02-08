// output linear ordering of vertices of the graph
// u->v (vertex u comes before vertex v)
// done using slightly modified both dfs and bfs..
// works on DAG(Directed Acyclic Graphs..)
/// topological sort using bfs : Kahn's algorithm
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

   
    void bfstopologicalsort()
    {
        queue<T> q;
        map<T,bool> visited;
        map<T,int> indegree;
        for(auto i:adjList){
            // i is pair of node and its list
            T node =i.first;
            visited[node]=false;
            indegree[node]=0;

        }
        // initialization of the indegrees of all the nodes

        for(auto i:adjList){

            T u=i.first;
            for(T v:adjList[u]){
                indegree[v]++;
            }
        }
        // find out all the nodes with 0 indegree
        for(auto i: adjList){
            T node=i.first;
            if(indegree[node]==0){
                q.push(node);
            }
        }

        // start with the algorithm

        while(!q.empty()){

            T node=q.front();
            q.pop();
            cout<<node<<"-->";

            for(T neighbour:adjList[node]){
                indegree[neighbour]--;

                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }


        }
    }
};

int main(int argc, char const *argv[])
{

    Graph<string> g;

    g.addEdge("english", "programming logic", false);
    g.addEdge("maths", "programming logic", false);
    g.addEdge("programming logic", "html", false);
    g.addEdge("programming logic", "python", false);
    g.addEdge("programming logic", "java", false);
    g.addEdge("programming logic", "js", false);
    g.addEdge("python", "web dev", false);
    g.addEdge("html", "css", false);
    g.addEdge("css", "js", false);
    g.addEdge("js", "web dev", false);
    g.addEdge("java", "web dev", false);
    g.addEdge("python", "web dev", false);
    g.bfstopologicalsort();

    return 0;
}
