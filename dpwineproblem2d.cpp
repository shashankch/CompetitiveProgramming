

#include <bits/stdc++.h>
#include <algorithm>
#include <iomanip>
using namespace std;

/// o(2^n)two branches..
int maxprofit(int arr[], int be, int en, int year)
{

    if (be > en)
    {
        return 0;
    }

    int q1 = arr[be] * year + maxprofit(arr, be + 1, en, year + 1);
    int q2 = arr[en] * year + maxprofit(arr, be, en - 1, year + 1);

    int ans = max(q1, q2);

    return ans;
}

int cnt = 0;
int memo[100][100];
///memoization o(n^2)
int maxprofitmemo(int arr[], int be, int en, int year)
{

    ++cnt;
    if (be > en)
    {
        return 0;
    }
    if (memo[be][en] != -1)
        return memo[be][en];

    int q1 = arr[be] * year + maxprofit(arr, be + 1, en, year + 1);
    int q2 = arr[en] * year + maxprofit(arr, be, en - 1, year + 1);

    int ans = max(q1, q2);
    memo[be][en] = ans;

    return ans;
}

/// bottom up approach:
int maxprofitdp(int arr[], int n)
{

    int dp[100][100] = {};
    int year = n;
    for (int i = 0; i < n; i++)
    {

        dp[i][i] = year * arr[i];
    }
    --year;
    for (int len = 2; len <= n; len++)
    {

        int start = 0;
        int end = n - len;
        while (start <= end)
        {
            int endwindow = start + len - 1;
            dp[start][endwindow] = max(arr[start] * year + dp[start + 1][endwindow],
                                       arr[endwindow] * year + dp[start][endwindow - 1]);
            ++start;
        }
        --year;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(3) << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[0][n - 1];
}

int main()
{
    int n;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(memo, -1, sizeof memo);
    int ans = maxprofitdp(arr, n);
    cout << ans << endl;
    cout << cnt;
    return 0;
}
