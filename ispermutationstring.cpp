

#include <iostream>
#include <cstring>
using namespace std;

bool ispermutations(char *s1, char *s2)
{

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    if (l1 != l2)
    {
        return false;
    }

    int freq[26] = {0};

    for (int i = 0; i < l1; i++)
    {

        freq[s1[i] - 'a']++;
    }

    for (int i = 0; i < l2; i++)
    {

        freq[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {

        if (freq[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{

    char s1[100], s2[100];
    cin >> s1;
    cin >> s2;
    if (ispermutations(s1, s2))
    {

        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}
