
#include <iostream>

using namespace std;

int searchIn(int arr[], int low, int high, int k)
{

    int mid;

    if (low > high)
    {
        return -1;
    }
    mid = (low + high) / 2;
    if (arr[mid] == k)
    {
        return mid;
    }

    ///key is lying in the first line of the graph.
    if (arr[low] <= arr[mid])
    {
        ///left part
        if (arr[low] <= k && arr[mid] >= k)
        {

            return searchIn(arr, low, mid - 1, k);
        }
        else
        {
            ///right part
            return searchIn(arr, mid + 1, high, k);
        }
    }
    ///second line key is lying
    if (arr[mid] <= k && arr[high] >= k)
    {

        ///right part is sorted
        return searchIn(arr, mid + 1, high, k);
    }
    ///left part
    return searchIn(arr, low, mid - 1, k);
}
int main()
{

    int n, k, arr[10003];
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    cin >> k;
    cout << searchIn(arr, 0, n - 1, k);

    return 0;
}
