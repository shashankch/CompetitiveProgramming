#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
const int MAX_CHAR = 256;
using namespace std;

ll countsubseq(string str)
{

    ll dp[str.length() + 1];

    for (ll i = 0; i <= str.length(); i++)
    {
        dp[i] = 0;
    }
    ll prev[MAX_CHAR];
    for (ll i = 0; i < MAX_CHAR; i++)
    {
        prev[i] = -1;
    }

    dp[0] = 1; //empty string
    for (ll i = 1; i <= str.length(); i++)
    {

        dp[i] = (dp[i - 1] * 2) % MOD;

        if (prev[str[i - 1]] != -1)
        {
            dp[i] = ((dp[i] - dp[prev[str[i - 1]]]) + MOD) % MOD;
        }
        prev[str[i - 1]] = i - 1;
    }
    return dp[str.length()] % MOD;
}

int main(int argc, char const *argv[])
{

    ll t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;

        cout << countsubseq(str) % MOD << endl;
    }

    return 0;
}