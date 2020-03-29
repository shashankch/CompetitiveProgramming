
#include <iostream>
#define ll long long int
using namespace std;

int main()
{

    ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19};

    ll t, no;
    cin >> t;
    while (t--)
    {

        cin >> no;

        ll subsets = (1 << 8) - 1;
        ll ans = 0;

        for (ll i = 1; i <= subsets; i++)
        {

            ll denom = 1ll;
            ll setbits = __builtin_popcount(i);

            for (ll j = 0; j <= 7; j++)
            {
                if (i & (1 << j))
                {
                    denom = denom * prime[j];
                }
            }
            if (setbits & 1)
            {
                ans += no / denom;
            }
            else
            {
                ans -= no / denom;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
