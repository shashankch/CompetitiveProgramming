#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Node
{

public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {

        if (size == 0)
            return true;
        else
            return false;
    }

    void push(T element)
    {

        Node<T> *newnode = new Node<T>(element);
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
        size++;
    }

    T pop()
    {

        if (head != NULL)
        {
            T data = head->data;
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            size--;
            return data;
        }
        else
        {

            return 0;
        }
    }

    T top()
    {

        if (head != NULL)
        {

            return head->data;
        }
        else
        {

            return 0;
        }
    }
};