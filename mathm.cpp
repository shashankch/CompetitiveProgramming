
#include <iostream>
#include <string>
using namespace std;
int main()
{

    int t;
    string s1, s2;
    cin >> t;

    cin >> s1;
    cin >> s2;

    while (t--)
    {

        for (int i = 0; i < s1.length(); i++)
        {

            if (s1[i] == s2[i])
            {
                s1[i] = '0';
            }
            else
            {
                s1[i] = '1';
            }
        }
    }

    cout << s1;

    return 0;
}
