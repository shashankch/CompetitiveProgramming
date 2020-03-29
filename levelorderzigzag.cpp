
#include <iostream>
#include <stack>
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
int height(node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int ls = height(root->left);
    int rs = height(root->right);

    return max(ls, rs) + 1;
}
void printkthlevel(node *root, int k)
{

    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {

        cout << root->data << " ";
        return;
    }

    printkthlevel(root->left, k - 1);
    printkthlevel(root->right, k - 1);
    return;
}

void printkthlevel2(node *root, int k)
{

    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {

        cout << root->data << " ";
        return;
    }

    printkthlevel(root->right, k - 1);
    printkthlevel(root->left, k - 1);
    return;
}
void levelorder(node *root)
{

    int h = height(root);

    for (int i = 0; i < h; i++)
    {

        if (i % 2 == 0)
        {
            printkthlevel(root, i);
        }
        else
        {
            printkthlevel2(root, i);
        }
        //cout<<endl;
    }
    return;
}

void zigzagtraversal(node *root)
{

    stack<node *> a;
    stack<node *> b;
    a.push(root);

    bool lr = true;
    while (!a.empty() or !b.empty())
    {

        int row = 0;
        if (a.size() > b.size())
        {
            row = a.size();
        }
        else
        {
            row = b.size();
        }

        while (row--)
        {

            if (lr)
            {

                node *temp = a.top();
                a.pop();
                cout << temp->data << " ";
                if (temp->left != NULL)
                {
                    b.push(temp->left);
                }
                if (temp->right != NULL)
                {
                    b.push(temp->right);
                }
            }
            else
            {

                node *temp = b.top();
                b.pop();
                cout << temp->data << " ";
                if (temp->right != NULL)
                {
                    a.push(temp->right);
                }
                if (temp->left != NULL)
                {
                    a.push(temp->left);
                }
            }
        }
        lr = !lr;
    }
}

int main()
{

    node *temp = buildtree("true");
    //levelorder(temp);
    zigzagtraversal(temp);

    return 0;
}
