

#include <iostream>

using namespace std;

void permute(char *in, int i)
{

    ///base case : when input is so small // when reach the end of the char array.
    if (in[i] == '\0')
    {
        cout << in << endl;
        return;
    }
    /// recursive case: swap the current char with next char and call for remaining array
    /// i : current char // j-i to.. for traversing.
    for (int j = i; in[j] != '\0'; j++)
    {

        swap(in[i], in[j]); /// going down the tree.
        permute(in, i + 1); /// call for the remaining char array
        swap(in[i], in[j]); /// backtracking : restoring the original array going up the tree
    }
}
int main()
{

    char in[100];
    cin >> in;
    permute(in, 0);

    return 0;
}
