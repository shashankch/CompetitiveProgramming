
#include <bits/stdc++.h>
using namespace std;
int *stockSpan(int *price, int size)
{
    // Write your code here
    stack<int> s;
    int *ans = new int[size];
    ans[0] = 1;
    s.push(0);
    for (int i = 1; i < size; i++)
    {

        while (!s.empty() && price[s.top()] < price[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = i + 1;
        }
        else
        {
            ans[i] = i - s.top();
        }

        s.push(i);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int size = 8;
    int arr[] = {60, 70, 80, 100, 90, 75, 80, 120};
    int *ans = stockSpan(arr, size);
    return 0;
}
