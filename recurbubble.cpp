

#include <iostream>

using namespace std;

void recurbubble(int *arr, int n)
{

    if (n == 1)
        return;

    for (int j = 0; j < n - 1; j++)
    {

        if (arr[j] >= arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }

    return recurbubble(arr, n - 1);
}
void recurbubble2(int arr[], int j, int n)
{

    if (n == 1)
        return;

    if (j == n - 1)
    {
        return recurbubble2(arr, 0, n - 1);
    }

    if (arr[j] > arr[j + 1])
    {

        swap(arr[j], arr[j + 1]);
    }
    return recurbubble2(arr, j + 1, n);
}

int main()
{

    int arr[] = {1, 3, 5, 4, 7, 4};

    int n = sizeof(arr) / sizeof(int);

    recurbubble2(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
