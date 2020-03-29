#include <iostream>
using namespace std;

//best case: O(n) i.e when there is mismatch in the first char of pattern.
// worst case:O(m*(n-m+1)) : O(n*m) : i.e when last char of pattern is not matched. or when duplicate chars. are there
void naivesearch(string str, string pat)
{

    for (int i = 0; i <= str.size() - pat.size(); i++)
    {

        int j;
        for (j = 0; j < pat.size(); j++)
        {

            if (str[i + j] != pat[j])
            {
                break;
            }
        }
        if (j == pat.size())
        {
            cout << "pattern is found at:" << i << endl;
        }
    }
}

int main(int argc, char const *argv[])
{
    string str, pat;
    cin >> str >> pat;
    naivesearch(str, pat);
    return 0;
}
