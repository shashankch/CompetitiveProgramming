
#include <iostream>
#define ll long long int
using namespace std;

ll maxgold(ll n, ll dp[])
{

	if (n == 0 || n == 1)
	{
		return n;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}

	dp[n] = max(n, maxgold(n / 2, dp) + maxgold(n / 3, dp) + maxgold(n / 4, dp));

	return dp[n];
}

int main(int argc, char const *argv[])
{

	ll n;
	cin >> n;
	ll dp[n + 1];
	for (ll i = 0; i <= n; i++)
	{
		dp[i] = -1;
	}

	cout << maxgold(n, dp) << endl;
	return 0;
}