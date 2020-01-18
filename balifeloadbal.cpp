
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    int arr[9001];
    long sum;

    while(cin >> n)
    {
        sum = 0;
        if(n == -1)
        {
            break;
        }

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        long avg = sum / n;
        if(avg * n != sum)
        {
            cout << "-1\n";
            continue;
        }

        for(int i = 0; i < n; i++)
        {
            arr[i] -= avg;
        }

        for(int i = 1; i < n; i++)
        {
            arr[i] += arr[i - 1];
        }

        long max = 0;
        for(int i = 0; i < n; i++)
        {
            if(max < abs(arr[i]))
            {
                max = abs(arr[i]);
            }
        }

        cout << max << endl;
    }

    return 0;
}
