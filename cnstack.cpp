
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

void reverseStack(stack<int> &s1, stack<int> &s2)
{
  
    if (s1.empty() || s1.size() == 1)
    {

        return;
    }

    int top = s1.top();
    s1.pop();

    reverseStack(s1, s2);

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(top);
    while (!s2.empty())
    {

        s1.push(s2.top());
        s2.pop();
    }
}

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