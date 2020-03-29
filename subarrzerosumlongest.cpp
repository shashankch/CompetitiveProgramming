

#include <iostream>
#include <unordered_map>
using namespace std;

int longestsubsumzero(int *arr, int n)
{

    unordered_map<int, int> m;
    int pre = 0;
    int longest = 0;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (arr[i] == 0 and longest == 0)
            longest = 1;
        if (pre == 0)
            longest = max(longest, i + 1);
        if (m.find(pre) != m.end())
        {
            longest = max(longest, i - m[pre]);
        }
        else
        {
            m[pre] = i;
        }
    }

    return longest;
}
int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int len = longestsubsumzero(arr, n);
    cout << len << endl;

    return 0;
}
