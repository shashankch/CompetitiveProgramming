
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        int arr[n];
        unordered_map<int, bool> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp.insert(make_pair(arr[i], true));
        }

        int q;
        cin >> q;
        while (q--)
        {
            int k;
            cin >> k;
            if (mp[k] == true)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}
