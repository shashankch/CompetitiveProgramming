
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{

    char ch[100];
    string str;
    cin >> str;
    cin.getline(ch, 100, '.');
    getline(cin, str);
    char test[] = {'a', 'b', '\0'}; ///always add null character in this type of initialization..
    char test2[] = "hello";         /// automatically null character is added here..hence size is 6
    cout << sizeof(test2);

    int length = str.length();
    reverse(str.begin(), str.end()); /// reverse is present in algo header.
    cout << str;
    string ss("hello");

    string hey;
    cin >> hey;
    int n = hey.length();
    for (int i = 0; i < n / 2; i++)
    {

        swap(hey[i], hey[n - i - 1]);
    }
    cout << hey;

    return 0;
}
