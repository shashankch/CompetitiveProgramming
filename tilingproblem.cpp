
#include <iostream>
using namespace std;

int ways(int n)
{
    if (n < 1)
        return 0;
    if (n < 4)
        return 1;
    if (n == 4)
        return 2;
    return ways(n - 1) + ways(n - 4);
}

int tilingways(int n, int m)
{

    if (m < 1)
        return 0;
    if (m < n)
        return 1;

    if (n == m)
        return 2;

    int x = tilingways(n, m - 1);
    int y = tilingways(n, m - n);

    return x + y;
}

int main()
{

    cout << tilingways(4, 5) << endl;
    cout << ways(5);

    return 0;
}
