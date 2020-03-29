
#include <iostream>
using namespace std;

int countset(int n)
{

    int c = 0;
    while (n > 0)
    {

        c++;
        n = n & (n - 1);
    }

    return c;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int a;
        cin >> a;
        cout << countset(a) << endl;
    }

    return 0;
}
