
#include <bits/stdc++.h>
#include <queue>
#include <map>
using namespace std;

class node
{

public:
    int data;
    int hd;
    node *left;
    node *right;

    node(int d)
    {
        hd = INT_MAX;
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildtree()
{

    queue<node *> q;
    int d;
    cin >> d;
    node *root = new node(d);
    q.push(root);
    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;

        if (l != -1)
        {

            temp->left = new node(l);
            q.push(temp->left);
        }
        if (r != -1)
        {

            temp->right = new node(r);
            q.push(temp->right);
        }
    }

    return root;
}

void bottomview(node *root)
{

    if (root == NULL)
    {
        return;
    }

    int hd = 0;

    map<int, int> m;

    queue<node *> q;

    root->hd = hd;

    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        hd = temp->hd;

        m[hd] = temp->data;

        if (temp->left != NULL)
        {
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            temp->right->hd = hd + 1;
            q.push(temp->right);
        }
    }

    for (auto i = m.begin(); i != m.end(); i++)
    {
        cout << i->second << " ";
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

    node *root = buildtree();
    ///printpre(root);
    bottomview(root);

    return 0;
}
