#include <iostream>
#include <string>
using namespace std;
int main()
{

    string str;

    cin >> str;
    int freq[256] = {0};
    for (int i = 0; i < str.length(); i++)
    {

        freq[str[i]]++;
    }

    int cm = 0, pos;
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] != 0)
        {
            if (cm < freq[i])
            {
                cm = freq[i];
                pos = i;
            }
        }
    }

    cout << (char)pos;

    return 0;
}
