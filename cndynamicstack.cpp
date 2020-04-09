
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class stackusingarray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    stackusingarray()
    {
        capacity = 4;
        data = new T[capacity];
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
            T *newarr = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newarr[i] = data[i];
            }

            delete[] data;
            data = newarr;
            capacity *= 2;
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
            return 0;
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

    stackusingarray<int> *s = new stackusingarray<int>();
    stackusingarray<int> stk;
    stk.push(10);

    return 0;
}