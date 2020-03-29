
#include <iostream>
#include <unordered_map>
#include <climits>
#define ll long long int
using namespace std;

int main()
{

    ll n;
    cin >> n;
    unordered_map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {

        ll x;
        cin >> x;
        mp[x]++;
    }

    ll k = -1;
    ll val = -1;
    for (auto i : mp)
    {

        if (i.second >= k)
        {
            k = i.second;
            val = i.first;
        }
    }
    cout << val << endl;

    return 0;
}
