
#include <iostream>
using namespace std;

int lowerbin(int n, int arr[], int val)
{

    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == val)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > val)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int upperbin(int n, int arr[], int val)
{

    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == val)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > val)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{

    int n, arr[10005];
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    int t;
    cin >> t;
    while (t--)
    {

        int val;
        cin >> val;
        cout << lowerbin(n, arr, val) << " " << upperbin(n, arr, val) << endl;
    }

    return 0;
}
