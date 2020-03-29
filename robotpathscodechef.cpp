

#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int dp[1001][1001];

int robotpaths(int r, int c)
{

    /// base case
    if (dp[0][0] == -1)
    {
        return 0;
    }

    /// compute the no.of ways for first row
    for (int j = 0; j < c; j++)
    {

        if (dp[0][j] == -1)
        {
            break;
        }
        dp[0][j] = 1;
    }

    /// compute the no.of ways for first col
    for (int j = 0; j < c; j++)
    {

        if (dp[j][0] == -1)
        {
            break;
        }
        dp[j][0] = 1;
    }

    ///bottom up dp

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            /// cell is blocked
            if (dp[i][j] == -1)
            {
                continue;
            }
            dp[i][j] = 0;
            if (dp[i][j - 1] != -1)
            {
                dp[i][j] = dp[i][j - 1] % MOD;
            }
            if (dp[i - 1][j] != -1)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }
    ///check for the final cells
    if (dp[r - 1][c - 1] == -1)
    {
        return 0;
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[r - 1][c - 1];
}

int main()
{

    memset(dp, 0, sizeof(dp));
    int m, n, p;
    cin >> m >> n >> p;
    for (int i = 0; i < p; i++)
    {
        int x, y;
        cin >> x >> y;
        dp[x - 1][y - 1] = -1;
    }

    cout << robotpaths(m, n) << endl;

    return 0;
}
