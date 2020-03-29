
#include <iostream>
using namespace std;

/// this is brute force approach : O(n^6)
int submatrixsum1(int **arr, int n, int m)
{

    int sum = 0;

    /// top left for each cell in the matrix
    for (int li = 0; li < n; li++)
    {

        for (int lj = 0; lj < m; lj++)
        {

            /// bottom left for each cell in the matrix
            for (int bi = li; bi < n; bi++)
            {

                for (int bj = lj; bj < m; bj++)
                {

                    /// traversing the rectangles i.e all submatrices.

                    for (int p = li; p <= bi; p++)
                    {

                        for (int q = lj; q <= bj; q++)
                        {

                            sum += arr[p][q];
                        }
                    }
                }
            }
        }
    }

    return sum;
}

///second approach: using prefix sum :O(n^4)
int submatrixsum2(int **arr, int n, int m)
{

    int sum = 0;
    ///prefix sum calculation--------------->>>
    int prefix[n][m];
    prefix[0][0] = arr[0][0]; ///initialize first cell to first value.

    for (int i = 1; i < m; i++)
    {

        prefix[0][i] = prefix[0][i - 1] + arr[0][i]; /// add prefix sum for first row and columns...>>>
    }
    for (int i = 1; i < n; i++)
    {

        prefix[i][0] = prefix[i - 1][0] + arr[i][0];
    }

    ///add prefix sum for rest rows and colns.
    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j < m; j++)
        {

            /// upper part+left part+diagonalpart prefix sums for each cell.to calculate current cell prefix sum..
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << prefix[i][j] << " ";
        }
        cout << endl;
    }

    /////////////////////////////////////////////////////////////////////////
    /// top left for each cell in the matrix
    for (int li = 0; li < n; li++)
    {
        int vv = 0, pp = 0, qq = 0, rr = 0; /// update the non required part variables ....to zero.
        for (int lj = 0; lj < m; lj++)
        {

            /// bottom left for each cell in the matrix
            for (int bi = li; bi < n; bi++)
            {

                for (int bj = lj; bj < m; bj++)
                {

                    vv = prefix[bi][bj]; /// prefix sum upto (x,y) bottom right
                    if (li - 1 >= 0)
                    {
                        pp = prefix[li - 1][bj]; /// remove upper part not required..
                    }
                    if (lj - 1 >= 0)
                    {
                        qq = prefix[bi][lj - 1]; /// remove left not required part.
                    }
                    if (li - 1 >= 0 && lj - 1 >= 0)
                    {
                        rr = prefix[li - 1][lj - 1]; /// add cell removed twice above..
                    }

                    sum = sum + vv - pp - qq + rr;
                }
            }
        }
    }
    return sum;
}

/// third approach : most efficient approach O(n^2) time and O(1) space
int submatrixsum3(int **arr, int n, int m)
{

    int sum = 0;

    ///find no. of all submatrices..
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ///finding each cell and then finding number of submatrices that cell is part of..
            /// no.of cell in the top left part..
            int tl = (i + 1) * (j + 1);
            ///no.of cells in the bottom right..
            int br = (n - i) * (n - j);
            sum += (tl * br * arr[i][j]);
        }
    }
    return sum;
}

int main()
{

    int n, m;

    cin >> n >> m;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {

        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 1;
        }
    }

    ///cout<<submatrixsum1(arr,n,m)<<endl;
    ///cout<<submatrixsum2(arr,n,m)<<endl;
    cout << submatrixsum3(arr, n, m) << endl;

    return 0;
}
