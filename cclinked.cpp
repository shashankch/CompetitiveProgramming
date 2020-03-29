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
void push(node *&head, int data)
{

    node *temp = head;

    node *n = new node(data);

    if (head != NULL)
    {

        while (temp->next != head)
        {

            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }
    else
    {

        n->next = n;
        head = n;
    }
}

bool found(node *head, int data)
{

    node *temp = head;
    while (temp->next != head)
    {

        if (temp->data == data)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}
void buildcycle(node *&head)
{

    node *temp = head;
    node *p;
    while (temp->next != head)
    {

        if (found(temp->next, temp->data))
        {
            p = temp;
            break;
        }
        temp = temp->next;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = p;
}

void cycleremoval(node *&head)
{

    node *slow = head;
    node *fast = head;
    node *prev;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {

            break;
        }
    }

    slow = head;

    while (slow != fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = NULL;
}
void print(node *head)
{

    while (head != NULL)
    {

        cout << head->data << "->";
        head = head->next;
    }
    //cout<<"length:"<<length(head)<<endl;

    cout << endl;
}
void printc(node *head)
{

    node *temp = head;
    while (temp->next != head)
    {

        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << temp->data << "end";
}

int main()
{

    node *head = NULL;
    while (1)
    {
        int n;
        cin >> n;
        if (n == -1)
        {
            break;
        }

        push(head, n);
    }

    buildcycle(head);
    cycleremoval(head);
    print(head);

    return 0;
}
