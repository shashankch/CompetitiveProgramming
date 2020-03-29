
#include <iostream>
#include <vector>
#include <queue>
#define ll long long int
using namespace std;
void query_print(priority_queue<ll, vector<ll>, greater<ll>> pq, ll k)
{
    while (k > 1)
    {
        pq.pop();
        k--;
    }
    cout << pq.top() << endl;
}
int main()
{
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll q, k;
    cin >> q >> k;
    ll query, x, y;
    ll l = 0;
    for (ll i = 0; i < q; i++)
    {
        cin >> query;
        if (query == 2 && l >= k)
        {
            query_print(pq, k);
        }
        else
        {
            cin >> x >> y;
            l++;
            pq.push(abs(x * x) + abs(y * y));
        }
    }
    return 0;
}
