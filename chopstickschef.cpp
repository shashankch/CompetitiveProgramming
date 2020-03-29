///Problem Code: TACHSTCK CODECHEF

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

    ll n, k;
    cin >> n >> k;
    vector<ll> v;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    ll count = 0;
    for (ll i = 0; i < n - 1; i++)
    {

        if (v[i + 1] - v[i] <= k && v[i + 1] - v[i] != 0)
        {
            count++;
            i++;
        }
        else
        {
            continue;
        }
    }
    cout << count;

    return 0;
}
