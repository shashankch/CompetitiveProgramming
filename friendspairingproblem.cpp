
#include <iostream>
using namespace std;

int dp[1000];
int friendpairways(int n)
{

    if (dp[n] != -1)
    {
        return dp[n];
    }

    if (n > 2)
    {
        /// nth friend alone so for rest f(n-1)+now out of n-1 friend select n-1C1 friends and rest n-2 friends..
        return dp[n] = friendpairways(n - 1) + (n - 1) * friendpairways(n - 2);
    }
    else
    {
        return dp[n] = n;
    }
}

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    cout << endl;
    cout << friendpairways(n);
    return 0;
}
