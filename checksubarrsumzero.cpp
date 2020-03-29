
#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{

    int arr2[] = {6, -1, 2, 1, -1};
    int arr[] = {1, 2, 3, 4, 5};
    unordered_set<int> s;
    int pre = 0;
    int i;
    for (i = 0; i < 5; i++)
    {
        pre += arr[i];
        if (pre == 0 or s.find(pre) != s.end())
        {
            cout << "yes";
            break;
        }
        s.insert(pre);
    }
    if (i == 5)
    {
        cout << "NO";
    }

    return 0;
}
