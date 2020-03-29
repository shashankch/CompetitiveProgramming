
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

ll ans = -1;

ll searching(ll arr[], ll low, ll high, ll val)
{

    if (low > high)
    {
        return ans;
    }

    ll mid = (low + high) / 2;
    if (arr[mid] == val)
    {
        ans = mid;
        searching(arr, mid + 1, high, val);
    }
    else if (arr[mid] > val)
    {
        searching(arr, low, mid - 1, val);
    }
    else
    {
        searching(arr, mid + 1, high, val);
    }

    return ans;
}

ll foundno(ll arr[], ll n, ll val)
{

    ///return searching(arr,0,n-1,val);

    if (n < 0)
    {
        return -1;
    }

    if (arr[n] == val)
    {
        return n;
    }

    foundno(arr, n - 1, val);
}
/*
int lastindex(int[] arr, int num, int si) {
        if (si == arr.length)
            return -1;

        int li = lastindex(arr, num, si + 1);
        if (li != -1)
            return li;

        else {
            if (arr[si] == num)
                return si;
            else
                return -1;
        }

    }

*/

/*
int lastindex(int *arr,int n,int m, int i){
if(i==n){
return -1;
}
int rr = lastindex(arr,n,m,i+1);
if(rr == -1 and arr[i] == m){
return i;
}else{
return rr;
}

}
*/

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
    //sort(arr,arr+n);
    cout << foundno(arr, n - 1, val);

    return 0;
}
