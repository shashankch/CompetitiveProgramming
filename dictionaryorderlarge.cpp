
#include <iostream>
#include <cstring>
using namespace std;

bool compare(string a, string b)
{

    if (a > b)
    {
        return true;
    }

    return false;
}

void dictionarylarge(char *in, int i, char *cpy)
{

    ///base case : when input is so small // when reach the end of the char array.
    if (in[i] == '\0')
    {

        if (compare(in, cpy))
        {
            cout << in << endl;
        }
        return;
    }
    /// recursive case: swap the current char with next char and call for remaining array
    /// i : current char // j-i to.. for traversing.
    for (int j = i; in[j] != '\0'; j++)
    {

        swap(in[i], in[j]);              /// going down the tree.
        dictionarylarge(in, i + 1, cpy); /// call for the remaining char array
        swap(in[i], in[j]);              /// backtracking : restoring the original array going up the tree
    }
}
int main()
{

    char in[100], cpy[100];

    cin >> in;
    strcpy(cpy, in);
    dictionarylarge(in, 0, cpy);

    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

void lexicoLarger(string str, string osf, bool flag, string originalString) {
    if(str.size() == 0) {
        if(osf.compare(originalString)!=0)
            cout << osf << endl;
        return;
    }
    for(int i = 0; i < str.size(); i++) {
        string ros = str.substr(0, i) + str.substr(i+1);
        char ch = str[i];
        if(flag) {
            lexicoLarger(ros, osf+ch, flag, originalString);
        } else {
            if(str[i] >= str[0]) {
                lexicoLarger(ros, osf+ch, flag or ch > str[0], originalString);
            } else if(str[i] < str[0]) {
                // No call
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
    lexicoLarger(str, "", false, str);
    return 0;
}

*/
