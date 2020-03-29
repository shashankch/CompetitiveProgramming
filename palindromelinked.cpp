
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
node *reverserecur(node *&head)
{

    ///base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    /// recursive case;
    node *smallhead = reverserecur(head->next);
    node *curr = head;
    curr->next->next = curr;
    curr->next = NULL;
    /// node *curr=head; node * prev=NULL; node
    ///

    return smallhead;
}
int length(node *head)
{

    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len += 1;
    }
    return len;
}

bool ispalindrome(node *head, node *rev)
{

    if (length(head) != length(rev))
    {
        return false;
    }

    while (head != NULL && rev != NULL)
    {

        if (head->data != rev->data)
        {
            return false;
        }
        head = head->next;
        rev = rev->next;
    }

    return true;
}

int main()
{

    node *head = NULL;
    node *head2 = NULL;
    int n, data;
    cin >> n;
    while (n--)
    {
        cin >> data;
        insertattail(head, data);
        insertattail(head2, data);
    }
    node *rev = reverserecur(head2);
    if (ispalindrome(head, rev))
    {

        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}
