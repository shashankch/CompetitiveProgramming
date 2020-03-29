
#include <iostream>
using namespace std;

void insertion(int n, int arr[])
{

    int curr, j;

    for (int i = 1; i < n; i++)
    {
        curr = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > curr; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = curr;
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

    insertion(n, arr);
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << endl;
    }

    return 0;
}
