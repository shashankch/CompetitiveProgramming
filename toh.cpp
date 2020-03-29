

#include <iostream>
using namespace std;

void toh(char a, char b, char c, int n)
{

    if (n == 1)
    {

        cout << "move " << n << "from" << a << " to" << c << endl;
        return;
    }
    else
    {
        toh(a, c, b, n - 1);
        cout << "move " << n << "from" << a << " to" << c << endl;
        toh(b, a, c, n - 1);
    }
}

int main()
{

    int nn;
    cin >> nn;
    toh('A', 'B', 'C', nn);

    long signed CodingBlocks = 2017;
    short unsigned BOSS1 = -2018;
    unsigned BOSS2 = -2019;
    int BOSS3 = -2020;
    long long unsigned BOSS4 = -2021;
    short unsigned Nagarro = 2018.9;
    long signed HackerBlocks = 'A';
    cout << CodingBlocks << endl;
    cout << BOSS1 << endl
         << BOSS2 << endl
         << BOSS3 << endl
         << BOSS4 << endl;
    cout << Nagarro << endl;
    cout << HackerBlocks << endl;

    return 0;
}
