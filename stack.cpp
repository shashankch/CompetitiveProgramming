
#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename X>
class stack
{

private:
    vector<T> v;
    vector<X> v2;

public:
    void push(T data)
    {

        v.push_back(data);
    }

    void pop()
    {

        if (!empty())
        {
            v.pop_back();
        }
    }

    T top()
    {

        return v[v.size() - 1];
    }
    bool empty()
    {

        return v.size() == 0;
    }
};

int main()
{

    stack<char, int> s;

    for (int i = 65; i <= 70; i++)
    {
        s.push(i);
    }
    //s.push(1);
    //s.push(2);
    //s.push(3);
    //s.push(4);
    //s.push(5);
    //s.pop();
    //cout<<s.top();
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
/// implementation of stack using linked list is expensive when elements are inserted at tail..
/// for implementation of stack using linked list insert element at head and for deletion just move the head ....
/// for implementation using array just restrict the array to return element at any index...
