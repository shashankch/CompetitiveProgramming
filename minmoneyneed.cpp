
#include <bits/stdc++.h>
using namespace std;

int minmoneyneed(int n, int w, int *arr)
{

    vector<int> val;
    vector<int> wt;

    for (int i = 0; i < w; i++)
    {

        if (arr[i] != -1)
        {
            val.push_back(arr[i]);
            wt.push_back(i + 1);
        }
    }

    n = val.size();
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= w; i++)
        dp[0][i] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= w; j++)
        {

            if (wt[i - 1] <= j)
            {
                dp[i][j] = min(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (dp[n][w] == INT_MAX)
    {
        return -1;
    }
    else
        return dp[n][w];
}

int main()
{

    int n, w;
    cin >> n >> w;
    int arr[w];
    for (int i = 0; i < w; i++)
    {
        cin >> arr[i];
    }

    cout << minmoneyneed(w, w, arr) << endl;

    return 0;
}