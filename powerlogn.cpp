
#include <iostream>

using namespace std;

int powerlogn(int a, int p)
{

    int ans = 1;
    int pow = a;
    while (p != 0)
    {

        if (p & 1)
        {
            ans *= pow;
        }
        pow *= pow;
        p = p >> 1;
    }

    return ans;
}

int main()
{

    int a, p;
    cin >> a >> p;

    cout << powerlogn(a, p);

    return 0;
}
