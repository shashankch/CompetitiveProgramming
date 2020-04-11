#include <iostream>
#include "Node.cpp"
using namespace std;

int length(Node<int> *head)
{

    int c = 0;
    Node<int> *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

Node<int> *addequal(Node<int> *h1, Node<int> *h2, int &carry)
{
    if (h1 == NULL)
    {
        return NULL;
    }
    int sum = 0;
    Node<int> *result = new Node(sum);
    result->next = addequal(h1->next, h2->next, carry);
    sum = h1->data + h2->data + carry;
    carry = sum / 10;
    sum %= 10;
    result->data = sum;

    return result;
}
void addleftcarry(Node<int> *h1, Node<int> *temp, int &carry, Node<int> *head)
{

    int sum;
    if (h1 != temp)
    {

        addleftcarry(h1->next, temp, carry, head);
        sum = h1->data + carry;
        carry = sum / 10;
        sum %= 10;
        Node<int> *newnode = new Node<int>(sum);
        newnode->next = head;
        head = newnode;
    }
}

void addnumber(Node<int> *h1, Node<int> *h2, Node<int> *head)
{

    Node<int> *temp;
    if (h1 == NULL)
    {

        head = h2;
        return;
    }
    else if (h2 == NULL)
    {
        head = h1;

        return;
    }

    int len1 = length(h1);
    int len2 = length(h2);
    int carry = 0;
    if (len1 == len2)
    {
        head = addequal(h1, h2, carry);
    }
    else
    {

        int diff = abs(len1 - len2);
        if (len1 < len2)
        {
            Node<int> *temp = h1;
            h1 = h2;
            h2 = temp;
        }
        Node<int> *temp = h1;
        while (diff-- > 0)
        {
            temp = temp->next;
        }
        head = addequal(temp, h2, carry);
        addleftcarry(h1, temp, carry, head);
    }

    if (carry)
    {
        Node<int> *newnode = new Node<int>(carry);
        newnode->next = head;
        head = newnode;
    }
}

int main()
{
    Node<int> *h1 = NULL, *h2 = NULL, *h = NULL;
    addnumber(h1, h2, h);

    return 0;
}