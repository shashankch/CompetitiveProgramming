
#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    int t, a, b;
    cin >> t;
    while (t--)
    {
        int cnt = 0;
        cin >> a >> b;

        int *prime = new int[1000001];
        for (int i = 2; i <= b; i++)
        {
            prime[i] = 1;
        }
        prime[0] = prime[1] = 0;
        for (int i = 2; i <= b; i++)
        {

            if (prime[i] == 1)
            {

                for (int j = 2 * i; j <= b; j += i)
                {
                    prime[j] = 0;
                }
            }
        }

        for (int i = a; i <= b; i++)
        {
            if (prime[i])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
