/// approach based on fibonnaci series..........
/// here a and b is given where b can't be consecutive in forming number..
#include <iostream>
using namespace std;

/// another approach
void assignment(int n)
{

    int a[n], b[n];
    a[0] = b[0] = 1;
    for (int i = 1; i <= n; i++)
    {

        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i - 1];
    }

    cout << "#"
         << "case"
         << " : " << a[n - 1] + b[n - 1] << endl;
}

int main()
{

    int digits[44];

    digits[0] = 0;
    digits[1] = 2;
    digits[2] = 3;

    for (int i = 3; i < 44; i++)
    {

        digits[i] = digits[i - 1] + digits[i - 2];
    }

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        cout << "#" << i << " : " << digits[n] << endl;
    }

    assignment(3);

    return 0;
}
