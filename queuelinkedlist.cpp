
/// linked list implementation using queue.........

#include <iostream>
#include <list>
using namespace std;

class queue
{

    int cs;
    list<int> arr;

public:
    queue()
    {

        cs = 0;
    }

    bool isempty()
    {

        return cs == 0;
    }

    void enqueue(int data)
    {

        arr.push_back(data);
        cs += 1;
    }

    void dequeue()
    {

        if (!isempty())
        {
            cs -= 1;
            arr.pop_front();
        }
    }

    int getfront()
    {

        return arr.front();
    }
};

int main()
{

    queue q;
    for (int i = 1; i < 6; i++)
    {

        q.enqueue(i);
    }
    q.dequeue();
    q.enqueue(89);
    while (!q.isempty())
    {
        cout << q.getfront() << " ";
        q.dequeue();
    }

    return 0;
}
