
#include <iostream>
#include <deque>
using namespace std;

int main()
{

    int n, k, a[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    deque<int> q(k);
    int i;
    for (i = 0; i < k; i++)
    {
        while (!q.empty() && a[i] > a[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    ///for the remaining elements..
    for (; i < n; i++)
    {

        ///print max for previous window
        cout << a[q.front()] << " ";

        /// contraction element removal not in the window  from front....
        while (!q.empty() && q.front() <= (i - k))
        {
            q.pop_front();
        }

        /// remove the element not useful in the current window..  from back..
        while (!q.empty() && a[i] >= a[q.back()])
        {
            q.pop_back();
        }
        /// add the new elements expansion...
        q.push_back(i);
    }

    return 0;
}
