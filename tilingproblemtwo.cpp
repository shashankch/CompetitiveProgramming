#include <iostream>
#include <cmath>
#define ll long long int
#define mod 1000000007
using namespace std;

int tileways(int n, int m)
{

    int count[n + 1];
    count[0] = 0;

    for (int i = 1; i <= n; i++)
    {

        if (i > m)
            count[i] = (count[i - 1] + count[i - m]) % mod;

        else if (i < m)
            count[i] = 1;

        else
            count[i] = 2;
    }

    return count[n] % mod;
}

ll tilingproblem(ll n, ll m)
{

    if (n < 0)
    {

        return 0;
    }
    if (n == m)
    {
        return 2;
    }
    if (1 <= n < m)
    {
        return 1;
    }
    return tilingproblem(n - 1, m) + tilingproblem(n - m, m);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n, m;
        cin >> n >> m;
        cout << tileways(n, m) << endl;
        // cout<<tilingproblem(n,m)%mod<<endl;
    }

    return 0;
}
