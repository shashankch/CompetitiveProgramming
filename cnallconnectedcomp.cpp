#include <bits/stdc++.h>

using namespace std;

void printBFS(int **edges, int n, bool *visited, int sv, vector<int> *v)
{

    queue<int> pendingVertices;

    pendingVertices.push(sv);
    visited[sv] = true;
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        v->push_back(currentVertex);
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
// void print(int **edges, int n, int sv, bool *visited)
// {

//     cout << sv << endl;
//     visited[sv] = true;
//     for (int i = 0; i < n; i++)
//     {
//         if (i == sv)
//         {
//             continue;
//         }

//         if (edges[sv][i] == 1)
//         {
//             if (visited[i])
//             {
//                 continue;
//             }
//             print(edges, n, i, visited);
//         }
//     }
// }

bool allvisit(bool *visit, int n)
{

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            return false;
        }
    }
    return true;
}

vector<vector<int> *> *allconnected(int **edges, int n)
{

    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {

        visited[i] = false;
    }
    vector<vector<int> *> *out = new vector<vector<int> *>();

    while (allvisit(visited, n) != true)
    {

        for (int i = 0; i < n; i++)
        {

            if (!visited[i])
            {
                vector<int> *small = new vector<int>;
                printBFS(edges, n, visited, i, small);
                out->push_back(small);
            }
        }
    }

    return out;
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

    // bool *visited = new bool[n];
    // for (int i = 0; i < n; i++)
    // {
    //     visited[i] = false;
    // }
    //print(edges, n, 0, visited);

    // printBFS(edges, n, 0);

    vector<vector<int> *> *output = allconnected(edges, n);
    for (int i = 0; i < output->size(); i++)
    {
        vector<int> *comp = output->at(i);
        sort(comp->begin(), comp->end());
        for (int j = 0; j < comp->size(); j++)
        {
            cout << comp->at(j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {

        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}