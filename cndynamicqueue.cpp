#include <iostream>
using namespace std;

template <typename T>
class queueusingarray
{

    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    queueusingarray(int s)
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getsize()
    {
        return size;
    }

    bool isempty()
    {
        return size == 0;
    }

    void enqueue(T element)
    {

        if (size == capacity)
        {
            // cout << "queue full" << endl;
            // return;

            T *newData = new T[2*capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity;i++){
                newData[j++] = data[i];
            }
            for (int i = 0; i < firstIndex;i++){
                newData[j++] = data[i];
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
           

            capacity = 2 * capacity;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }

    T front()
    {

        if (isempty())
        {
            cout << "empty q" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue()
    {

        if (isempty())
        {
            cout << "queue is empty" << endl;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
};