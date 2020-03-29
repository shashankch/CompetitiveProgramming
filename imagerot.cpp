

#include <iostream>
#include <algorithm>
using namespace std;

void image(int arr[][10], int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(arr[j][i], arr[n - 1 - j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate2(int arr[][10], int n)
{

    for (int i = 0; i < n; i++)
    {

        int sc = 0, ec = n - 1;
        while (sc < ec)
        {

            swap(arr[i][sc], arr[i][ec]);

            sc++;
            ec--;
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (i < j)
            {

                swap(arr[i][j], arr[j][i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate_stl(int arr[][10], int n)
{

    for (int i = 0; i < n; i++)
    {

        reverse(arr[i], arr[i] + n);
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {

            if (i < j)
            {

                swap(arr[i][j], arr[j][i]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cin >> n;
    int arr[10][10];

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    rotate_stl(arr, n);

    return 0;
}
