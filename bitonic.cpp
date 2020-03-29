
#include <iostream>
using namespace std;

int bitonic(int *arr, int n)
{

    int i = 0, next = 0, start = 0, ms = 1;
    while (i < n - 1)
    {

        while (i < n - 1 && arr[i] <= arr[i + 1])
        {
            i++;
        }

        while (i < n - 1 && arr[i] >= arr[i + 1])
        {

            if (i < n - 1 && arr[i] > arr[i + 1])
            {
                next = i + 1;
            }

            i++;
        }
        ms = max(ms, i - start + 1);
        start = next;
    }

    return ms;
}

//finding bitonic using left and right ascend and descend array
int bitonic2(int *arr, int n)
{

    int *left = new int[n];
    int *right = new int[n];

    left[0] = 1;
    right[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {

        if (arr[i] >= arr[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
        else
        {
            left[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {

        if (arr[i] >= arr[i + 1])
        {
            right[i] = right[i + 1] + 1;
        }
        else
        {
            right[i] = 1;
        }
    }

    int ms = left[0] + right[0] - 1;

    for (int i = 1; i < n; i++)
    {

        ms = max((left[i] + right[i] - 1), ms);
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
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << bitonic2(arr, n) << endl;
    }

    return 0;
}
