
#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{

    unordered_map<int, int> mymap;

    int a[] = {1, 3, 2, 5, 7};
    int b[] = {2, 5, 6, 9, 11};
    for (int i = 0; i < 5; i++)
    {

        mymap[a[i]] = a[i];
    }

    cout << "Intersection values:";
    for (int i = 0; i < 5; i++)
    {

        if (mymap.find(b[i]) != mymap.end())
        {
            cout << b[i] << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < 5; i++)
    {

        mymap[b[i]] = b[i];
    }
    cout << "Union values:";
    for (auto my : mymap)
    {
        cout << my.first << " ";
    }

    return 0;
}
