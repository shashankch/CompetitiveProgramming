#include <bits/stdc++.h>

using namespace std;

void printBFS(int **edges, int n, int sv)
{

    queue<int> pendingVertices;
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {

        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {

            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

    delete[] visited;
}

// dfs implementation.. going in depth first.
void print(int **edges, int n, int sv, bool *visited)
{

    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }

        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

vector<int> *helper(int **edges, int n, int sv, int ev, bool *visited)
{
   
}

vector<int> *getpath(int **edges, int n, int sv, int ev)
{
    queue<int> bfsq;
    bool *visited = new bool[n];
    for (int i = 0; i < n;i++){
        visited[i] = false;
    }
    bfsq.push(sv);
    bool done = false;
    map<int, int> parent;
    visited[sv] = true;
    while(!bfsq.empty() && !done){
        int front = bfsq.front();
        bfsq.pop();
        for (int i = 0; i < n;i++){
            if(edges[front][i] && !visited[i]){
                parent[i] = front;
                bfsq.push(i);
                visited[i] = true;
                if(i==ev){
                    done = true;
                    break;
                }
            }
        }
    }
    if(!done){
        return NULL;
    }
    else{
        vector<int> *out = new vector<int>();
        int curr = ev;
        out->push_back(ev);
        while(curr!=ev){
            curr = parent[curr];
            out->push_back(curr);
        }
        return out;
    }

    delete[] visited;
}

int main()
{

    int n;
    int e;

    cin >> n >> e;
    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {

        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {

        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    print(edges, n, 0, visited);

    printBFS(edges, n, 0);

    int sv, ev;
    cin >> sv >> ev;

    vector<int> *ans = getpath(edges, n, sv, ev);
    if (ans != NULL)
    {
        for (int i = 0; i < ans->size(); i++)
        {
            cout << ans->at(i) << endl;
        }
    }
    else
    {
        cout << "no path" << endl;
    }

    for (int i = 0; i < n; i++)
    {

        delete[] edges[i];
    }

    delete[] edges;
    delete[] visited;
}