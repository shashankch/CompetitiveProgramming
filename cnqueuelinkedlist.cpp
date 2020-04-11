#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{

public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue
{

    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {

        head = NULL;
        tail = NULL;
        size = 0;
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
        size++;
        Node<T> *nw = new Node<T>(element);
        if (head == NULL)
        {
            head = nw;
            tail = nw;
            return;
        }

        tail->next = nw;
        tail = nw;
    }

    T front()
    {

        if (isempty())
        {
            return 0;
        }
        return head->data;
    }

    T dequeue()
    {

        if (isempty())
        {
            return 0;
        }

        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;

        return ans;
    }
};
void reverseQueue(queue<int> &q)
{
    // Write your code here

    if (q.size() <= 1)
    {
        return;
    }

    int top = q.front();
    q.pop();

    reverseQueue(q);
    q.push(top);
}
int main()
{

    ///inbuilt queue..

    queue<int> q;
    q.push(39);
    q.pop();
    int top = q.front();
    bool ans = q.empty();
    int s = q.size();
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}