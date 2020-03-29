
#include <iostream>
using namespace std;

template <typename T>
class queue
{

    T *arr;
    int front;
    int rear;
    int cs;
    int ms;

public:
    queue(int ds = 4)
    {

        front = 0;
        rear = ms - 1;
        cs = 0;
        ms = ds;
        arr = new T[ms];
    }

    bool isFull()
    {

        return cs == ms;
    }

    bool isEmpty()
    {

        return cs == 0;
    }

    void push(T data)
    {

        if (!isFull())
        {
            rear = (rear + 1) % ms;
            arr[rear] = data;
            cs++;
        }
    }

    void pop()
    {

        if (!isEmpty())
        {
            front = (front + 1) % ms;
            cs--;
        }
    }

    T getFront()
    {

        return arr[front];
    }
};

int main()
{

    queue<int> q2;
    queue<int> q(10);
    for (int i = 0; i <= 6; i++)
    {

        q.push(i);
    }
    q.pop();
    q.push(8);

    while (!q.isEmpty())
    {

        cout << q.getFront() << " ";
        q.pop();
    }

    return 0;
}

/// for implementation of queue using linked list insert element at tail keep track of tail.
/// and head for the front ...
/// implement queue using circular queue by traversing (front or rear+1)%N for front and rear ...here using fixed size array..
///implemented using dynamic array..
