
#include <bits/stdc++.h>

using namespace std;

void printbfs(int **edges, int n, int sv, bool *visited)
{

    queue<int> pendingVertices;

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
}

// dfs implementation.. going in depth first.
void printdfs(int **edges, int n, int sv, bool *visited)
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
            printdfs(edges, n, i, visited);
        }
    }
}

void bfs(int **edges, int n)
{
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printbfs(edges, n, i, visited);
    }
    delete[] visited;
}

void dfs(int **edges, int n)
{

    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printdfs(edges, n, i, visited);
    }
    delete[] visited;
}

bool isconnected(int **edges, int n)
{
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // here 0 is considered as start vertex..
    printdfs(edges, n, 0, visited);
    // or call bfs
    // printbfs(edges,n,0,visited);
    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {
            return false;
        }
    }
    return true;
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

    cout << "dfs" << endl;
    dfs(edges, n);
    cout << "bfs" << endl;
    bfs(edges, n);

    if (isconnected(edges, n))
    {

        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    for (int i = 0; i < n; i++)
    {

        delete[] edges[i];
    }

    delete[] edges;
}