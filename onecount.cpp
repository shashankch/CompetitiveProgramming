
#include <iostream>
using namespace std;

void countone(int *arr, int n, int k)
{

    int lw = 0, rw = 0, bwin = 0, zero = 0, bl = 0;

    while (rw < n)
    {

        if (zero <= k)
        {
            if (arr[rw] == 0)
                zero++;

            rw++;
        }
        if (zero > k)
        {

            if (arr[lw] == 0)
            {
                zero--;
            }
            lw++;
        }
        if ((rw - lw) > bwin and (zero <= k))
        {

            bwin = rw - lw;
            bl = lw;
        }
    }
    cout << bwin << endl;
    for (int i = 0; i < bl; i++)
    {

        cout << arr[i] << " ";
    }

    for (int i = bl; i < bl + bwin; i++)
    {

        if (arr[i] == 0)
        {
            arr[i] = 1;
        }
        cout << arr[i] << " ";
    }

    for (int i = bl + bwin; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void onecount2(int *arr, int n, int k)
{

    int s = -1, e = -1;
    int l = 0, r = 0;
    int maxlen = 0;
    while (l < n)
    {

        while (r < n)
        {

            if (arr[r] == 0)
            {

                if (k > 0)
                {
                    k--;
                    r++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                r++;
            }
        }
        int curr = r - l;
        maxlen = max(curr, maxlen);
        s = l;
        e = r;

        if (arr[l] == 0)
        {
            k++;
        }
        l++;
    }

    cout << maxlen << endl;
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = s; i < e; i++)
    {
        if (arr[i] == 0)
        {
            arr[i] = 1;
        }
        cout << arr[i] << " ";
    }
    for (int i = e; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void onecount(int *arr, int n, int k)
{

    int l = 0;
    int r = 0;
    int zero = 0;
    int maxlen = 0;
    int s = -1, e = -1;
    while (l < n && r < n)
    {

        if (arr[r] == 1)
        {
            r++;
        }
        else if (arr[r] == 0)
        {
            zero++;

            r++;
        }

        while (zero > k)
        {

            if (arr[l] == 0)
            {
                zero--;
            }
            l++;
        }
        int curr = r - l;
        maxlen = max(curr, maxlen);
        s = l;
        e = r;
    }

    cout << maxlen << endl;
    for (int i = s; i < e; i++)
    {
        arr[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    countone(arr, n, k);

    return 0;
}
