

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool compare(string a, string b)
{

    if (a < b)
    {
        return true;
    }

    return false;
}

void dictionarylarge(string in, int i, string cpy)
{

    ///base case : when input is so small // when reach the end of the char array.
    if (i >= in.length())
    {

        if (compare(in, cpy))
        {
            cout << in << endl;
        }
        return;
    }
    /// recursive case: swap the current char with next char and call for remaining array
    /// i : current char // j-i to.. for traversing.
    for (int j = i; j < in.length(); j++)
    {

        swap(in[i], in[j]);              /// going down the tree.
        dictionarylarge(in, i + 1, cpy); /// call for the remaining char array
                                         /// swap(in[i],in[j]); /// backtracking : restoring the original array going up the tree
                                         /// here in case of strings we don't have to backtrack because it is not passed as reference hence it does'nt change...
    }
}
int main()
{

    string in, cpy;

    cin >> in;
    cpy = in;
    dictionarylarge(in, 0, cpy);

    return 0;
}
