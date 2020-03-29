
#include <iostream>
#define ll long long int
using namespace std;

/// bottom up ..
ll countstrings(ll n)
{

    ll a[n], b[n];

    a[0] = 1, b[0] = 1;
    for (int i = 1; i < n; i++)
    {

        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i - 1];
    }

    return a[n - 1] + b[n - 1];
}

/// top down approach : here in this problem recurrence relation of fibonacci can also be used.
/// f(n)=f(n-1)+f(n-2)
ll dp[100][2];
ll countstringtopdp(int n, int last)
{

    if (n == 1)
    {

        return 1;
    }

    if (dp[n][last] != -1)
    {

        return dp[n][last];
    }

    if (last == 0)
    {

        dp[n][last] = countstringtopdp(n - 1, 1) + countstringtopdp(n - 1, 0);
    }

    else
    {

        dp[n][last] = countstringtopdp(n - 1, 0);
    }

    return dp[n][last];
}

int countbinarystrings(int n, int last)
{

    if (n == 1)
    {
        return 1;
    }
    if (last == 0)
    {
        return countbinarystrings(n - 1, 0) + countbinarystrings(n - 1, 1);
    }
    else if (last != 0)
    {

        return countbinarystrings(n - 1, 0);
    }
}
int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                dp[i][j] = -1;
            }
        }
        int n;
        cin >> n;
        ///  cout<<countbinarystrings(n,0)+countbinarystrings(n,1)<<endl;
        /// cout<<countstrings(n)<<endl;
        ll ans = countstringtopdp(n, 1) + countstringtopdp(n, 0);
        cout << ans << endl;
    }

    return 0;
}
