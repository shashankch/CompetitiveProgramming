#include <iostream>
using namespace std;

bool checksum(int arr[], int n, int no, int sum)
{

    int csum = 0;
    int i = 0;
    while (no > 0)
    {

        if (no & 1)
        {
            csum += arr[i];
            ///cout<<csum<<endl;
        }

        i++;

        no = no >> 1;
    }
    if (csum == sum)
        return true;

    else
        return false;
}

bool ispossible(int arr[], int n, int k)
{

    int range = (1 << n) - 1;
    for (int i = 1; i <= range; i++)
    {
        if (checksum(arr, n, i, k))
        {
            return true;
        }
    }

    return false;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        if (ispossible(arr, n, k))
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }

    // your code goes here
    return 0;
}
