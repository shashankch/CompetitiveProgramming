#include <iostream>
using namespace std;

int knapsackvalue(int n, int kw, int *val, int *sz)
{

    int dp[kw + 1];

    for (int i = 0; i <= kw; i++)
        dp[i] = 0;
    for (int i = 0; i <= kw; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (sz[j] <= i)
            {
                dp[i] = max(val[j] + dp[i - sz[j]], dp[i]);
            }
        }
    }

    return dp[kw];
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
