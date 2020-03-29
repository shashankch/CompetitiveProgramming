
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
node *buildtree(string exist)
{

    if (exist == "true")
    {

        int d;
        cin >> d;
        node *root = new node(d);
        string lt;
        cin >> lt;
        if (lt == "true")
        {
            root->left = buildtree(lt);
        }
        string rt;
        cin >> rt;
        if (rt == "true")
        {
            root->right = buildtree(rt);
        }

        return root;
    }

    return NULL;
}

class check
{

    /// here we can use single variable height to represent balance part by setting it to -1..
public:
    int height;
    bool balance;
};

check isheightbalanced(node *root)
{

    check ch;
    if (root == NULL)
    {

        ch.height = 0;
        ch.balance = true;

        return ch;
    }

    check left = isheightbalanced(root->left);
    check right = isheightbalanced(root->right);

    ch.height = max(left.height, right.height) + 1;

    if (left.balance && right.balance && abs(left.height - right.height) <= 1)
    {

        ch.balance = true;
    }
    else
    {
        ch.balance = false;
    }

    return ch;
}

int main()
{

    node *temp = buildtree("true");
    check res = isheightbalanced(temp);
    if (res.balance)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}
