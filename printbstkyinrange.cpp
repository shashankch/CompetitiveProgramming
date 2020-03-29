
#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {

        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildbst(node *root, int data)
{

    if (root == NULL)
    {
        return new node(data);
    }

    if (data < root->data)
    {

        root->left = buildbst(root->left, data);
    }
    else if (data > root->data)
    {

        root->right = buildbst(root->right, data);
    }
    return root;
}

void printpre(node *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printpre(root->left);
    printpre(root->right);
}

void printrange(node *root, int a, int b)
{

    if (root == NULL)
    {

        return;
    }

    if (a < root->data)
    {
        printrange(root->left, a, b);
    }

    if (root->data >= a && root->data <= b)
    {

        cout << root->data << " ";
    }

    if (b > root->data)
    {

        printrange(root->right, a, b);
    }
}

int main()
{

    int t, a, b, n, data;
    cin >> t;

    while (t--)
    {

        node *root = NULL;
        cin >> n;
        for (int i = 0; i < n; i++)
        {

            cin >> data;
            root = buildbst(root, data);
        }
        cin >> a >> b;
        cout << "# Preorder : ";
        printpre(root);

        cout << endl;

        cout << "# Nodes within range are : ";
        printrange(root, a, b);
    }

    return 0;
}
