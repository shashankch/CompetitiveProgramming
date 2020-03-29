

/// overlapping subproblem

/// optimal substructure : local best=global best

#include <iostream>
using namespace std;

int maxprofit(int arr[], int totalen)
{

    if (totalen == 0)
        return 0;
    int best = 0;

    for (int len = 1; len <= totalen; len++)
    {

        int profit = arr[len] + maxprofit(arr, totalen - len);
        best = max(best, profit);
    }

    return best;
}

int memo[100];
int maxprofitmemo(int arr[], int totalen)
{

    if (totalen == 0)
        return 0;

    if (memo[totalen] != -1)
    {
        return memo[totalen];
    }

    int best = 0;

    for (int len = 1; len <= totalen; len++)
    {

        int profit = arr[len] + maxprofit(arr, totalen - len);
        best = max(best, profit);
    }
    memo[totalen] = best;
    return best;
}

///O(n^2)
int maxprofitdp(int arr[], int totalen)
{

    int dp[100] = {};

    for (int len = 1; len <= totalen; len++)
    {
        int best = 0;
        for (int cut = 1; cut <= len; cut++)
        {

            best = max(best, arr[cut] + dp[len - cut]);
        }

        dp[len] = best;
    }

    return dp[totalen];
}

int main()
{

    int totallen;
    int priceofeachlen[100];
    cin >> totallen;
    for (int piece = 1; piece <= totallen; piece++)
    {

        cin >> priceofeachlen[piece];
    }

    /// reset memo
    for (int i = 0; i <= totallen; i++)
    {
        memo[i] = -1;
    }
    int ans = maxprofitmemo(priceofeachlen, totallen);

    return 0;
}
