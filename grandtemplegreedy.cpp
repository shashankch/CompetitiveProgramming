
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {

        cin >> a[i] >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int max1 = a[0] - 1;
    int max2 = b[0] - 1;
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i + 1] - a[i] - 1) > max1)
        {
            max1 = (a[i + 1] - a[i] - 1);
        }
        if ((b[i + 1] - b[i] - 1) > max2)
        {
            max2 = (b[i + 1] - b[i] - 1);
        }
    }
    cout << max1 * max2;
}
