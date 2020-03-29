
#include <iostream>
#include <cstring>

using namespace std;

string table[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void smartkeycode(char *code, char *out, int i, int j)
{
    if (code[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    int digit = code[i] - '0';

    for (int p = 0; p < table[digit].length(); p++)
    {

        out[j] = table[digit][p];
        smartkeycode(code, out, i + 1, j + 1);
    }
}

int main()
{

    char code[100], out[100];
    cin >> code;

    smartkeycode(code, out, 0, 0);

    return 0;
}
