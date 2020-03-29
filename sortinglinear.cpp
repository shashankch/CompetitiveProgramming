

#include <iostream>
using namespace std;

void sortlinear(int n, int arr[])
{

    int l = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high)
    {

        if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
        else
        {
            swap(arr[mid], arr[l]);
            l++;
            mid++;
        }
    }
}

int main()
{
    int n, arr[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }

    sortlinear(n, arr);
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}
