
#include <iostream>
#include <string>
using namespace std;

void str_comp(string comp)
{

    for (int i = 0; i < comp.length(); i++)
    {

        int cnt = 1;
        while (i < comp.length() - 1 && comp[i] == comp[i + 1])
        {

            cnt++;
            i++;
        }

        cout << comp[i] << cnt;
    }
}
int main()
{

    string comp;
    cin >> comp;
    str_comp(comp);

    return 0;
}
