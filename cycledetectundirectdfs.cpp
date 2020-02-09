#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template <typename T>

class Graph
{

    map<T, list<T> > adjList;

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

    bool iscyclichelper(T node, map<T, bool> &visited,T parent)
    {
        visited[node]=true;
        for(T neighbour :adjList[node]){
            if(!visited[neighbour]){
                bool cycledetected=iscyclichelper(neighbour,visited,node);
                if(cycledetected){
                    return true;
                }
            }
            // in this neighbour is already visited..
            else if(neighbour!=parent){
                return true;
            }
        }
        return false;
    }
    // CHECK FOR UNDIRECTED  GRAPH USING DFS (RECURSIVE)
    bool iscyclicdfs()
    {
        map<T,bool>visited;
        // you can find cycle in dfs tree..
        for(auto i:adjList){
            T node=i.first;
            if(!visited[node]){
                bool ans=iscyclichelper(node,visited,node);
                if(ans==true){
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
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(4,3);

    if (g.iscyclicdfs())
    {
        cout << "cycle present !";
    }
    else
    {
        cout << "cycle not present";
    }

    return 0;
}
