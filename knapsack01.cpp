

#include <iostream>
using namespace std;

int knapsackvalue(int n, int kw, int *val, int *sz)
{

    int dp[n + 1][kw + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= kw; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= kw; j++)
        {

            if (sz[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - sz[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][kw];
}

int main()
{

    int n, kw;

    int s[1003], val[1003];
    cin >> n >> kw;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    cout << knapsackvalue(n, kw, val, s);

    return 0;
}
