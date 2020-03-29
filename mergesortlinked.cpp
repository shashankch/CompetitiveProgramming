#include <iostream>
#define ll long long int
using namespace std;

class node
{

public:
    ll data;
    node *next;

    node(ll d)
    {

        data = d;
        next = NULL;
    }
};

void insertattail(node *&head, ll data)
{

    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {

        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

node *mergesortedlist(node *a, node *b)
{

    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }

    node *c;
    /// compare a and b for smaller element to point temp as head of new list..

    if (a->data < b->data)
    {
        c = a;
        /// pointing the pointer of smallest values to the rest of sorted list.We assume returned by recursion.
        c->next = mergesortedlist(a->next, b);
    }
    else
    {
        c = b;
        /// pointing the pointer of smallest values to the rest of sorted list.We assume returned by recursion.

        c->next = mergesortedlist(a, b->next);
    }
    /// return original value from the call stack......
    return c;
}

void print(node *head)
{

    while (head != NULL)
    {

        cout << head->data << " ";
        head = head->next;
    }
    //cout<<"length:"<<length(head)<<endl;

    cout << endl;
}

int main()
{

    node *head = NULL;
    ll t;
    cin >> t;

    while (t--)
    {

        node *head1 = NULL;
        node *head2 = NULL;
        int n, data;
        cin >> n;
        for (int i = 0; i < n; i++)
        {

            cin >> data;
            insertattail(head1, data);
        }
        cin >> n;
        for (int i = 0; i < n; i++)
        {

            cin >> data;
            insertattail(head2, data);
        }

        node *temp = mergesortedlist(head1, head2);
        print(temp);
    }

    return 0;
}
