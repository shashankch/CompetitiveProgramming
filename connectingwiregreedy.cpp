
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int n = 2;
    int black[] = {2, 3};
    int white[] = {1, 4};
    sort(black, black + n);
    sort(white, white + n);
    int totallength = 0;
    for (int i = 0; i < n; i++)
    {

        int len = abs(black[i] - white[i]);
        totallength += len;
    }

    cout << totallength;

    return 0;
}
