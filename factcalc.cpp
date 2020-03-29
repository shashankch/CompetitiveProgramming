
#include <iostream>
using namespace std;
#define m 500

int mult(int x, int res[], int s)
{
    int carry = 0;
    for (int i = 0; i < s; i++)
    {

        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {

        res[s] = carry % 10;
        carry /= 10;
        s++;
    }

    return s;
}

void factorial(int n)
{

    int res[m];
    res[0] = 1;
    int s = 1;
    for (int x = 2; x <= n; x++)
    {
        s = mult(x, res, s);
    }

    for (int i = s - 1; i >= 0; i--)
    {
        cout << res[i];
    }
}

int main()
{

    int n;
    cin >> n;

    factorial(n);

    return 0;
}
