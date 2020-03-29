
#include <iostream>
#include <queue>
using namespace std;

class stack
{

    queue<int> a, b;

    int curr_size;

public:
    stack()
    {

        curr_size = 0;
    }

    void pop()
    {

        while (a.size() != 1)
        {

            b.push(a.front());
            a.pop();
        }

        a.pop();
        curr_size--;

        swap(a, b);
    }

    void push(int data)
    {

        a.push(data);
        curr_size++;
    }

    int top()
    {
        while (a.size() != 1)
        {

            b.push(a.front());
            a.pop();
        }
        int temp = a.front();

        a.pop();
        b.push(temp);
        swap(a, b);

        return temp;
    }
};

int main()
{

    stack s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    for (int i = 0; i < n; i++)
    {

        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
