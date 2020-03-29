
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool ispalindrome(string str)
{

    int l = 0;
    int r = str.length() - 1;
    while (l <= r)
    {

        if (str[l++] != str[r--])
        {
            return false;
        }
    }

    return true;
}

string substring(string str, int l, int h)
{

    string temp = "";
    for (int i = l; i < h; i++)
    {

        temp += str[i];
    }

    return temp;
}

void palindromepairs(vector<string> &words)
{

    unordered_map<string, int> mp;
    for (int i = 0; i < words.size(); i++)
    {
        mp[words[i]] = i;
    }

    ///prefix part..
    for (int i = 0; i < words.size(); i++)
    {

        for (int j = 0; j <= words[i].length(); j++)
        {

            string s1 = substring(words[i], 0, j);
            string temp1 = s1;
            string s2 = substring(words[i], j, words[i].length());
            string temp2 = s2;
            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());

            if (ispalindrome(temp1))
            {
                if (mp.find(s2) != mp.end() && mp[s2] != i)
                {
                    cout << "[ " << i << ", " << mp[s2] << " ]" << endl;
                }
            }

            if (ispalindrome(temp2))
            {
                if (mp.find(s1) != mp.end() && mp[s1] != i && temp2.length() != 0)
                {
                    cout << "[ " << i << ", " << mp[s1] << " ]" << endl;
                }
            }
        }
    }
}

int main()
{

    vector<string> words{"abcd", "dcba", "lls", "s", "sssll"};
    ///vector <string>words{"bat","tab","cat"};
    palindromepairs(words);

    return 0;
}
