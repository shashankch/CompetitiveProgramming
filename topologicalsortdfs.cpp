// output linear ordering of vertices of the graph
// u->v (vertex u comes before vertex v)
// done using slightly modified both dfs and bfs..
// works on DAG(Directed Acyclic Graphs..)

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

    void dfshelper(T node, map<T, bool> &visited,list<T> &ordering)
    {

        visited[node]=true;
        // will call dfs on the unvisited neighbours of the current node.

        for(T neighbour:adjList[node]){

            if(!visited[neighbour]){
                dfshelper(neighbour,visited,ordering);
            }
        }
        // add 1 line for TS
        // at this point,all the children of the current node have been visited.
        // so we can add current node to the list.
        ordering.push_front(node);

      
    }
    void dfstopologicalsort()
    {

        map<T,bool>visited;
        list<T> ordering;

        for(auto  i:adjList){

            // i is pair (node,list)
            T node=i.first;
            if(!visited[node]){
                dfshelper(node,visited,ordering);
            }
        }

    //print all the element in ordering
    for(T element:ordering){
        cout<<element<<"-->";
    }


    }
};

int main(int argc, char const *argv[])
{

    Graph<string> g;

    g.addEdge("english","programming logic",false);
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
    g.dfstopologicalsort();

    return 0;
}
