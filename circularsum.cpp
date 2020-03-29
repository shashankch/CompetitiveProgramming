#include <iostream>
using namespace std;

int kadane(int *arr, int n)
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

int max_circular(int *arr, int n)
{

    int c1 = kadane(arr, n);
    int cum = 0;
    for (int i = 0; i < n; i++)
    {
        cum += arr[i];
        arr[i] = -arr[i];
    }
    int c2 = cum + kadane(arr, n);

    return max(c1, c2);
}

int main()
{

    int t, n;

    cin >> t;
    while (t--)
    {

        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << max_circular(arr, n) << endl;
    }

    return 0;
}
