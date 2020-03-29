
///interviewbit problem

#include <iostream>
#include <unordered_map>

using namespace std;

int counttriangles(int *x, int *y)
{

    unordered_map<int, int> hx;
    unordered_map<int, int> hy;
    for (int i = 0; i < 3; i++)
    {
        if (hx.find(x[i]) == hx.end())
        {
            hx[x[i]] = 1;
        }
        else
        {
            hx[x[i]] += 1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (hy.find(y[i]) == hy.end())
        {
            hy[y[i]] = 1;
        }
        else
        {
            hy[y[i]] += 1;
        }
    }

    int total = 0;
    for (int i = 0; i < 3; i++)
    {

        int px = x[i];
        int py = y[i];
        if (hx.find(px) != hx.end() && hy.find(py) != hy.end())
        {
            int sum = (hx[px] - 1) * (hy[py] - 1);
            total += sum;
        }
    }

    return total;
}
int main()
{

    int x[] = {1, 1, 2};
    int y[] = {1, 2, 1};
    cout << counttriangles(x, y);
}
