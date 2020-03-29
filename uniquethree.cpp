
#include <iostream>

using namespace std;

void findunique(int arr[], int n)
{

    int freq[64] = {0};
    for (int i = 0; i < n; i++)
    {

        int curr = arr[i];
        int pos = 0;
        while (curr > 0)
        {

            if (curr & 1)
            {
                freq[pos]++;
            }
            pos++;
            curr = curr >> 1;
        }
    }
    for (int i = 0; i < 64; i++)
    {

        freq[i] = freq[i] % 3;
    }
    int ans = 0;
    int pow = 1;
    for (int i = 0; i < 64; i++)
    {

        ans += (freq[i] * pow);
        pow = pow * 2;
    }

    cout << ans;
}

int main()
{

    int n, arr[1003];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    findunique(arr, n);

    return 0;
}
