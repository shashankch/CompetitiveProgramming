#include <iostream>
using namespace std;

int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {

        bool flag = false;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= (1 << n) - 1; i++)
        {
            int csum = 0;
            int mask = 1;
            for (int j = 0; j < 31; j++)
            {

                if (i & (mask << j))
                {
                    csum += arr[j];
                }
            }

            if (csum == k)
            {
                flag = true;

                break;
            }
        }

        if (flag)
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
