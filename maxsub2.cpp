#include <iostream>
#include <algorithm>
using namespace std;

int max_sum2(int *arr, int n)
{
    int ms = 0, cs = 0;
    int *cum = new int[n];
    cum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        cum[i] = cum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = i; j < n; j++)
        {

            cs = 0;
            cs = cum[j] - cum[i - 1];
            ms = max(cs, ms);
        }
    }

    return ms;
}

int max_sum(int *arr, int n)
{

    int cs = 0, ms = 0;

    for (int i = 0; i < n; i++)
    {

        cs += arr[i];
        if (cs < 0)
        {
            cs = 0;
        }
        ms = max(ms, cs);
    }

    return ms;
}

int main()
{

    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << max_sum2(arr, n) << endl;
    }

    return 0;
}
