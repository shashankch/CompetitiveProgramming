#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

void searching(ll arr[], ll curr_index, ll val, ll N)
{

    if (curr_index == N)
    {
        return;
    }
    if (arr[curr_index] == val)
    {
        cout << curr_index << " ";
    }
    searching(arr, curr_index + 1, val, N);
}

int main()
{

    ll n, val;
    cin >> n;
    ll arr[n + 5];

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> val;

    searching(arr, 0, val, n);

    return 0;
}
