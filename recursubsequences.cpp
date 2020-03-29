
#include <iostream>
using namespace std;

void subseq(char *str, char *out, int i, int j)
{

    if (str[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    out[j] = str[i];
    subseq(str, out, i + 1, j + 1);

    subseq(str, out, i + 1, j);
}

int main()
{

    char str[100];
    char out[100];
    cin >> str;
    subseq(str, out, 0, 0);

    return 0;
}
