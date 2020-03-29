
#include <iostream>
#include <queue>
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

    if (data <= root->data)
    {

        root->left = buildbst(root->left, data);
    }
    else
    {

        root->right = buildbst(root->right, data);
    }

    return root;
}

node *deletebst(node *root, int data)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (data < root->data)
    {

        root->left = deletebst(root->left, data);
        return root;
    }
    else if (data == root->data)
    {

        ///for leaf nodes
        if (root->left == NULL && root->right == NULL)
        {

            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {

            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right != NULL && root->left == NULL)
        {

            node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {

            node *maxleft = root->left;
            while (maxleft->right != NULL)
            {
                maxleft = maxleft->right;
            }

            root->data = maxleft->data;
            root->left = deletebst(root->left, maxleft->data);

            return root;
        }
    }

    else
    {

        root->right = deletebst(root->right, data);
        return root;
    }
}

void printpre(node *root)
{ ///top down approach

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    printpre(root->left);
    printpre(root->right);
}

int main()
{

    int t, n, d;
    cin >> t;
    while (t--)
    {

        cin >> n;
        node *root = NULL;
        for (int i = 0; i < n; i++)
        {

            cin >> d;
            root = buildbst(root, d);
        }
        int m, del;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> del;
            root = deletebst(root, del);
        }
        printpre(root);
    }
    return 0;
}
