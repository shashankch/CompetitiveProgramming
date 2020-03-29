#include <iostream>
using namespace std;

///using dp technique
int dp[100] = {0};
int catalan(int n)
{

    if (n == 0)
    {
        return 1;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {

        ans += catalan(i - 1) * catalan(n - i);
    }

    dp[n] = ans;

    return ans;
}
/// catalan number formula : 2nCn/(n+1).
/// f(n)=summation(i=1 to n)[f(i-1)*f(n-i)].
/// used to calculate total no. of possible bsts. from the given no. of nodes.
///used to calculate total no.of unlabeled trees possible.
/// for calculating total no. of binary tree: [n! * 2nCn/(n+1)]. because we can permute node data..
/// calculating no. of expressions containing n pairs of parentheses which are correctly matched..

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {

        cout << catalan(i) << " ,";
    }

    return 0;
}
