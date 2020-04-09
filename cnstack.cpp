
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class stackusingarray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    stackusingarray(int totalsize)
    {
        capacity = totalsize;
        data = new T[totalsize];
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

    void push(T element)
    {

        if (nextIndex == capacity)
        {
            cout << "stack overflow" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop()
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

    T top()
    {

        if (!isEmpty())
        {
            return data[nextIndex - 1];
        }
    }
};

int main()
{

    stackusingarray<int> *s = new stackusingarray<int>(30);
    stackusingarray<int> stack(10);
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