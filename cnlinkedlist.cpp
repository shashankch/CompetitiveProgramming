#include <iostream>
using namespace std;
#include "Node.cpp"
void print(Node *head)
{
    // print all nodes condition is head!=NULL
    // if want to stop at end node: head->next!=NULL
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

Node *takeinput() // O(N^2)
{

    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1)
    {

        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
        cin >> data;
    }
    return head;
}

Node *takeinput_better() //O(N)
{

    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {

        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next; // or we can write : tail=newNode
        }
        cin >> data;
    }
    return head;
}

Node *insertNode(Node *head, int i, int data)
{

    Node *temp = head;
    Node *newNode = new Node(data);
    int count = 0;
    if (i == 0)
    {

        newNode->next = head;
        head = newNode;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {

        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {

        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

Node *reverse(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        // cout << head->data << endl;
        return head;
    }

    Node *smallhead = reverse(head->next);
    //  print(smallhead);
    cout << endl;
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;

    return smallhead;
}

class Pair
{
public:
    Node *head;
    Node *tail;
};

Pair reverseLL_2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverseLL_2(head->next);

    smallAns.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverseLL_Better(Node *head)
{
    return reverseLL_2(head).head;
}

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *smallAns = reverseLL(head->next);

    Node *temp = smallAns;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;
    head->next = NULL;
    return smallAns;
}

int findindex(Node *head, int x)
{

    if (head == NULL)
    {

        return -1;
    }

    if (head->data == x)
    {
        return 0;
    }

    int in = findindex(head->next, x);
    if (in != -1)
    {
        return in + 1;
    }

    return -1;
}

Node *evenafterodd(Node *head)
{

    if (head == NULL)
    {

        return head;
    }

    Node *oh = NULL;
    Node *ot = NULL;
    Node *eh = NULL;
    Node *et = NULL;

    while (head != NULL)
    {

        if (head->data % 2 == 0)
        {
            if (eh == NULL)
            {

                eh = head;
                et = head;
            }
            else
            {
                et->next = head;
                et = head;
            }
        }
        else
        {

            if (oh == NULL)
            {
                oh == head;
                ot = head;
            }
            else
            {

                ot->next = head;
                ot = head;
            }
        }
        head = head->next;
    }

    if (oh == NULL)
    {
        return eh;
    }

    else
    {

        oh->next = eh;
    }

    if (eh != NULL)
    {
        et->next = NULL;
    }

    return oh;
}

int length(Node *head)
{

    if (head == NULL)
    {
        return 0;
    }
    Node *temp = head;
    int size = length(temp->next);
    return size + 1;
}

Node *takeInput_Better()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            // OR
            // tail = newNode;
        }

        cin >> data;
    }
    return head;
}

Node *swap_nodes(Node *head, int i, int j)
{

    Node *curr = head, *prev = NULL;
    Node *onecurr = NULL;
    Node *oneprev = NULL;
    Node *twocurr = NULL;
    Node *twoprev = NULL;
    int pos = 0;
    while (curr != NULL)
    {

        if (pos == i)
        {

            onecurr = curr;
            oneprev = prev;
        }

        if (pos == j)
        {

            twocurr = curr;
            twoprev = prev;
        }

        pos++;
        prev = curr;
        curr = curr->next;
    }

    if (oneprev != NULL)
    {

        oneprev->next = twocurr;
    }

    else
    {

        head = twocurr;
    }

    if (twoprev != NULL)
    {

        twoprev->next = onecurr;
    }
    else
    {
        head = onecurr;
    }

    Node *temp = twocurr->next;
    twocurr->next = onecurr->next;

    onecurr->next = temp;

    return head;
}

Node *kReverse(Node *head, int n)
{

    int i = 0;
    Node *temp = head;
    Node *prev = NULL;
    Node *nxt = NULL;

    while (i < n && temp != NULL)
    {

        nxt = temp->next;
        temp->next = prev;

        prev = temp;
        temp = nxt;
        i++;
    }

    if (nxt != NULL)
    {
        head->next = kReverse(nxt, n);
    }

    return prev;
}

Node *bubble_sort(Node *head)
{

    int n = length(head);
    //cout<<n<<endl;
    for (int i = 0; i < n - 1; i++)
    {

        Node *curr = head;
        Node *prev = NULL;

        for (int j = 0; j < n - i - 1; j++)
        {

            if (curr->data <= curr->next->data)
            {

                prev = curr;
                curr = curr->next;
            }
            else
            {

                if (prev != NULL)
                {
                    Node *fwd = curr->next;
                    prev->next = fwd;
                    curr->next = fwd->next;
                    fwd->next = curr;
                    prev = fwd;
                }

                else
                {
                    head = head->next;
                    Node *fwd = curr->next;
                    curr->next = fwd->next;
                    fwd->next = curr;
                    prev = fwd;
                }
            }
        }
    }

    return head;
}

int main()
{

    // //static
    // Node n1(1);
    // // Node *head = &n1;
    // Node n2(2);

    // n1.next = &n2;

    // cout << n1.data << " " << n2.data << endl;

    // //dynamically
    // Node *n3 = new Node(10);
    // Node *head = n3;
    // Node *n4 = new Node(20);
    // n3->next = n4;
    // print(head);
    Node *head = takeinput();
    print(head);
    //  insertNode(head, 2, 99);
    //head = reverse(head);
    head = evenafterodd(head);
    cout << endl;
    print(head);

    return 0;
}
