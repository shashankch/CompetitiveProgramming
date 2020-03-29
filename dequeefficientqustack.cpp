
#include <iostream>
#include <stack>

using namespace std;

class queue
{

    stack<int> a, b;

public:
    void enqueue(int data)
    {

        while (!a.empty())
        {
            b.push(a.top());
            a.pop();
        }
        a.push(data);
        while (!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
    }

    int dequeue()
    { ///dequeue efficient operation ---->>> O(1) and enqueue operation ---->>> O(n) times

        int x;
        if (!a.empty())
        {
            x = a.top();
            a.pop();
        }

        return x;
    }

    int top()
    {

        return a.top();
    }
};

int main()
{

    int n;
    cin >> n;
    queue q;

    for (int i = 0; i < n; i++)
    {
        q.enqueue(i);
    }
    for (int i = 0; i < n; i++)
    {

        // cout<<q.top()<<" ";
        cout << q.dequeue() << " ";
    }

    return 0;
}
