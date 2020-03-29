

#include <iostream>
#include <bitset>
using namespace std;

bitset<30> col, d1, d2;

/// can be void function also then base case does not return anything.....
bool nqueen(int i, int n, int &ans)
{

    ///base case when all queens are placed row wise equals n
    if (i == n)
    {

        ans++;

        return false;
    }

    /// now try to place queen in the current row columnwise
    for (int j = 0; j < n; j++)
    {

        if (!col[j] && !d1[i - j + n - 1] && !d2[i + j])
        { /// queen is safe to place in that position .
            col[j] = d1[i - j + n - 1] = d2[i + j] = 1;
            /// call on the rest part of the board
            bool nextqueenrakhpaye = nqueen(i + 1, n, ans); /// no value need to be return in case of void func.just call
            if (nextqueenrakhpaye)
            {
                return true;
            }
            /// if reaches here that means not able to place queen
            /// backtracking if next queen we were not able to place on the board
            ///unset the all bitsets
            col[j] = d1[i - j + n - 1] = d2[i + j] = 0;
        }
    }

    /// program reaches here when there is no configuration ...
    ///...in the current row which is giving right for the next part of the board
    return false;
}
int main()
{

    int n;
    cin >> n;

    int ans = 0;
    bool res = nqueen(0, n, ans);
    cout << ans;

    return 0;
}
