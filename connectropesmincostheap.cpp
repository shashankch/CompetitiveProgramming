
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int connectropesmincost(int *ropes, int n)
{

    priority_queue<int, vector<int>, greater<int>> minheap(ropes, ropes + n);

    int cost = 0;
    while (minheap.size() > 1)
    {

        int firstmin = minheap.top();
        minheap.pop();
        int secondmin = minheap.top();
        minheap.pop();
        cost += (firstmin + secondmin);
        minheap.push(firstmin + secondmin);
    }

    return cost;
}

int main()
{

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    cout << connectropesmincost(arr, n);
    return 0;
}
