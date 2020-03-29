
#include <iostream>
#define ll long long int
using namespace std;

bool isortedarr(ll arr[], ll n)
{

    if (n == 1)
    {
        return true;
    }

    if (arr[0] <= arr[1] && isortedarr(arr + 1, n - 1))
    {
        return true;
    }

    return false;
}

int main()
{

    ll n;
    cin >> n;
    ll arr[n];

    for (ll i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    if (isortedarr(arr, n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}
