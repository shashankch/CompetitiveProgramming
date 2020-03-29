
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {

        data = d;
        next = NULL;
    }
};

void insertattail(node *&head, int data)
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

void print(node *head)
{

    while (head != NULL)
    {

        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

void insertionsort(node *&head)
{

    for (node *i = head->next; i != NULL; i = i->next)
    {

        for (node *j = head; j != i && j->data >= i->data; j = j->next)
        {

            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
}

int main()
{

    int n, data;
    node *head = NULL;
    cin >> n;
    while (n--)
    {

        cin >> data;

        insertattail(head, data);
    }

    insertionsort(head);
    print(head);

    return 0;
}
