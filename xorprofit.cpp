
#include <iostream>
using namespace std;

int maxor(int a, int b)
{

    int ans = 0;
    for (int i = a; i < b; i++)
    {

        ans = max(ans, i ^ (i + 1));
    }

    return ans;
}

int maxorimproved(int a, int b)
{

    int ans = a ^ b;
    int msb = 0;
    while (ans != 0)
    {
        ans = ans >> 1;
        msb++;
    }
    int res = 1;
    while (msb--)
    {
        res = res << 1;
    }

    return res - 1;
}

int main()
{

    int a, b;
    cin >> a >> b;
    cout << maxor(a, b);
    cout << maxorimproved(a, b);

    return 0;
}
