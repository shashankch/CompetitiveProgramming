
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = (int)1e9;

int reduce(int n)
{

    if (n == 1)
        return 0;

    int q1 = inf, q2 = inf, q3 = inf;
    if (n % 3 == 0)
    {
        q1 = 1 + reduce(n / 3);
    }
    if (n % 2 == 0)
    {
        q2 = 1 + reduce(n / 2);
    }
    q3 = 1 + reduce(n - 1);
    return min(q1, min(q2, q3));
}
/// top down memoization approach..
int memo[1000];
int reduce2(int n)
{

    if (n == 1)
        return 0;

    int q1 = inf, q2 = inf, q3 = inf;
    if (memo[n] != -1)
        return memo[n];

    if (n % 3 == 0)
    {
        q1 = 1 + reduce2(n / 3);
    }
    if (n % 2 == 0)
    {
        q2 = 1 + reduce2(n / 2);
    }
    q3 = 1 + reduce2(n - 1);

    memo[n] = min(q1, min(q2, q3));

    return memo[n];
}

/// bottom up approach..
int reducedp(int n)
{

    int dp[1000];
    dp[0] = 0;
    dp[2] = 1;
    dp[1] = 0;
    dp[3] = 1;

    for (int currnum = 4; currnum <= n; currnum++)
    {
        int q1, q2, q3;
        q1 = q2 = q3 = inf;

        if (currnum % 3 == 0)
            q1 = 1 + dp[currnum / 3];
        if (currnum % 2 == 0)
            q2 = 1 + dp[currnum / 2];
        q3 = 1 + dp[currnum - 1];

        dp[currnum] = min(q1, min(q2, q3));
    }

    return dp[n];
}

int main()
{

    int n;
    cin >> n;
    fill(memo, memo + n + 1, -1);
    cout << reduce(n);

    return 0;
}
