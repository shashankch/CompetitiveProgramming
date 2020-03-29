
#include <iostream>
#include <cstring>
using namespace std;

void filter(char *str, int no)
{

    int i = 0;
    while (no > 0)
    {

        (no & 1) ? cout << str[i] : cout << "";
        i++;

        no = no >> 1;
    }
}

void subsequences(char *str)
{

    int len = strlen(str);
    int range = (1 << len) - 1;
    for (int i = 1; i <= range; i++)
    {
        filter(str, i);
        cout << endl;
    }
}

int main()
{

    char str[100];
    cin >> str;
    subsequences(str);

    return 0;
}
