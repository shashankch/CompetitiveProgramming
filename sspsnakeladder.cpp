#include <iostream>
#include <climits>
#include <map>
#include <list>
#include <queue>
using namespace std;

//single source shortest path
// unweighted directed graph..
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

    int sssp(T src,T dest)
    {

        queue<T> q;
        map<T, T> dist;
        map<T, T> parent;

        for (auto i : adjList)
        {
            dist[i.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while (!q.empty())
        {
            T node = q.front();
          //  cout << node << " ";
            q.pop();

            // for the neighbours of the current node,find out the node which are not visited;
            for (int neighbour : adjList[node])
            {
                if (dist[neighbour] == INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }

        // print the distance of all the nodes from the source..
        // for (auto i : adjList)
        // {
        //     T node = i.first;
        //     cout << "Dist of " << node << " is " << dist[node] << endl;
        // }

        // you can go back from destination 
        T temp=dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp=parent[temp];
        }
        cout<<src<<endl;


        return dist[dest];
    }
};

int main()
{

    Graph<int> g;
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
  
    /// construct graph..add pairs of u,v
    for(int u=0;u<=36;u++){

        // dice throw at every node..
        for(int dice=1;dice<=6;dice++){
            int v=u+dice+board[u+dice];
            g.addEdge(u,v,false);
        }

    }


    cout<<"The shortest dist is "<<g.sssp(0,36)<<endl;
    return 0;
}
