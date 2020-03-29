
#include <iostream>
using namespace std;

/// recursive solution ....
int optimalgame(int *a, int i, int j)
{

    ///base case:
    ///when only one
    if (i == j)
    {
        return a[i];
    }
    /// when two elements

    if (i + 1 == j)
    {
        return max(a[i], a[j]);
    }

    ///Recursive case:

    /// player 1 takes ith coin.. leaving minimum possible values for player 2
    int ith = a[i] + min(optimalgame(a, i + 1, j - 1), optimalgame(a, i + 2, j));

    /// if user takes jth coin ..leaving minm possble vlues for player 2
    int jth = a[j] + min(optimalgame(a, i, j - 2), optimalgame(a, i + 1, j - 1));

    /// return the max of the two choices..

    return max(ith, jth);
}

/// top down approach..
long long dp[1002][1002];
long long optimal(long long *a, int i, int j)
{

    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    long long ci = a[i] + min(optimal(a, i + 2, j), optimal(a, i + 1, j - 1));
    long long cj = a[j] + min(optimal(a, i, j - 2), optimal(a, i + 1, j - 1));

    return dp[i][j] = max(ci, cj);
}

/// bottom up approach..dp

int optimalStrategyOfGame(int *arr, int n)
{
    // Create a table to store solutions of subproblems
    int table[n][n] = {};

    // Fill table using above recursive formula. Note
    // that the table is filled in diagonal fashion (similar
    // to http://goo.gl/PQqoS), from diagonal elements to
    // table[0][n-1] which is the result.
    for (int gap = 0; gap < n; ++gap)
    {
        for (int i = 0, j = gap; j < n; ++i, ++j)
        {

            // Here x is value of F(i+2, j), y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive formula
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0;

            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return table[0][n - 1];
}
int main()
{

    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1, n));
    /*
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
    pdp[i][j]=-1;
        }

}

cout<<optimaldp(arr,0,n-1);

*/
    return 0;
}
