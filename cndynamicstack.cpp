
#include <bits/stdc++.h>
using namespace std;

class stackusingarray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    stackusingarray()
    {
        capacity = 4;
        data = new int[capacity];
        nextIndex = 0;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int element)
    {

        if (nextIndex == capacity)
        {
            cout << "stack overflow" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop()
    {

        if (!isEmpty())
        {
            nextIndex--;
            return data[nextIndex];
        }
        else
        {
            cout << "empty" << endl;
            return INT_MIN;
        }
    }

    int top()
    {

        if (!isEmpty())
        {
            return data[nextIndex - 1];
        }
    }
};

int main()
{

    stackusingarray *s = new stackusingarray(30);
    stackusingarray stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    bool ans = stack.isEmpty();
    int top = stack.pop();
    int size = stack.size();
    int val = stack.top();

    return 0;
}