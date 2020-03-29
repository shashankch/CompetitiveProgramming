#include <bits/stdc++.h>

using namespace std;

int findminvertex(int *distance, bool *visited, int n)
{

    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {

        if (!visited[i] && (minvertex == -1 || distance[i] < distance[minvertex]))
        {
            minvertex = i;
        }
    }

    return minvertex;
}

void dijkstra(int **edges, int n)
{

    bool *visited = new bool[n];
    int *dist = new int[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {

        int minvertex = findminvertex(dist, visited, n);
        visited[minvertex] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[minvertex][j] != 0 && !visited[j])
            {
                int dis = dist[minvertex] + edges[minvertex][j];
                if (dis < dist[j])
                {
                    dist[j] = dis;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }

    delete[] visited;
    delete[] dist;
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
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }

    dijkstra(edges, n);
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }

    delete[] edges;

    return 0;
}

/*

5 7
0 1 4
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9
3 4 4



*/