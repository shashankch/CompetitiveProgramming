
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void shuffle(int arr[], int s, int e)
{

    srand(time(NULL));
    int randomIndex;
    for (int i = e; i > 0; i--)
    {

        randomIndex = rand() % (i + 1);
        swap(arr[i], arr[randomIndex]);
    }
}

int partitions(int arr[], int s, int e)
{

    int pivot = arr[e];
    int i = s - 1;
    int j = s;
    for (; j < e; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);

    return i + 1;
}
void quicksort(int arr[], int s, int e)
{

    if (s >= e)
    {
        return;
    }
    int p = partitions(arr, s, e);
    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main()
{

    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }
    shuffle(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }

    return 0;
}
