

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> cpair;

vector<int> mergeksortedarr(vector<vector<int>> arr)
{

    vector<int> result;

    priority_queue<cpair, vector<cpair>, greater<cpair>> pq;

    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }
    while (pq.empty() == false)
    {

        cpair temp = pq.top();
        pq.pop();
        int x = temp.second.first;
        int y = temp.second.second;
        result.push_back(temp.first);
        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }

    return result;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    //  vector<vector<int> > arr{{2,6,12,15},
    //  {1,9,13,15},
    // {20,24,30,32}
    // };

    vector<int> output = mergeksortedarr(arr);
    for (auto x : output)
    {
        cout << x << " ";
    }
    return 0;
}
