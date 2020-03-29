#include <iostream>
#include <cstring>
using namespace std;

int editdist(char inp[100], char out[100])
{

    int dp[101][101] = {};

    int m = strlen(inp);
    int n = strlen(out);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = dp[0][i - 1] + 1; ///insertion
    }
    for (int j = 1; j <= m; j++)
    {
        dp[j][0] = dp[j - 1][0] + 1; ///deletion
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            int rep = dp[i - 1][j - 1];
            int del = dp[i - 1][j];
            int ins = dp[i][j - 1];
            dp[i][j] = min(rep, min(del, ins)) + (inp[i - 1] != out[j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{
    char inp[100], out[100];
    cin >> inp >> out;

    int ans = editdist(inp, out);
    cout << ans;
    return 0;
}
