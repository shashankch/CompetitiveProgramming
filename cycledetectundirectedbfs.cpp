// for undirected graph check if node is already visited or not..

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

    void print(){

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

    //check for undirected graph
    bool isCyclicbfs(T src){

        map<T,bool> visited;
        map<T,int> parent;
        queue<T>q;
        q.push(src);
        visited[src]=true;
        parent[src]=src;

        while(!q.empty()){
            T node =q.front();
            q.pop();

            // iterate over the neighbours of that node leaving parent.
            for( T neighbour : adjList[node]){
                if(visited[neighbour]==true && parent[node]!=neighbour){  //modification in bfs..
                    return true;
                }
                else if(!visited[neighbour]){
                    visited[neighbour]=true;
                    parent[neighbour]=node;
                    q.push(neighbour);
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
    g.addEdge(4,3);
    g.addEdge(2,3);

    if(g.isCyclicbfs(1)){
        cout<<"Cyclic graph";
    }
    else{
        cout<<"Non cyclic";
    }

    return 0;
}
