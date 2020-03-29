
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

node *buildtree()
{

    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildtree();
    root->right = buildtree();

    return root;
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

void printpost(node *root)
{ ///bottom up approach

    if (root == NULL)
    {
        return;
    }
    printpre(root->left);
    printpre(root->right);
    cout << root->data << " ";
}

void printinorder(node *root)
{

    if (root == NULL)
    {
        return;
    }

    printpre(root->left);
    cout << root->data << " ";
    printpre(root->right);
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

    if (k == 1)
    {

        cout << root->data << " ";
        return;
    }

    printkthlevel(root->left, k - 1);
    printkthlevel(root->right, k - 1);
    return;
}

void levelorder(node *root)
{

    int h = height(root);

    for (int i = 1; i <= h; i++)
    {

        printkthlevel(root, i);
        cout << endl;
    }
    return;
}

///using queue..
void bfs(node *root)
{

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *fr = q.front();
        cout << fr->data << " ";
        q.pop();
        if (fr->left)
        {
            q.push(fr->left);
        }
        if (fr->right)
        {
            q.push(fr->right);
        }
    }

    return;
}
///using queue with pair --node * and int level...
///void bfs2()...

///using char null marker...
void bfs3(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *fr = q.front();
        if (fr == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            cout << fr->data << " ";
            q.pop();
            if (fr->left)
            {
                q.push(fr->left);
            }
            if (fr->right)
            {
                q.push(fr->right);
            }
        }
    }
    return;
}

int countnodes(node *root)
{

    if (root == NULL)
    {

        return 0;
    }

    return 1 + countnodes(root->left) + countnodes(root->right);
}

int sumnodes(node *root)
{

    if (root == NULL)
    {

        return 0;
    }

    return root->data + sumnodes(root->left) + sumnodes(root->right);
}

///O(N^2)
int diameter(node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);

    int d1 = h1 + h2;
    int d2 = diameter(root->left);
    int d3 = diameter(root->right);

    return max(d1, max(d2, d3));
}

class Pair
{

public:
    int diameter;
    int height;
};

///O(N)
Pair fastDiameter(node *root)
{

    Pair p;
    if (root == NULL)
    {

        p.diameter = p.height = 0;
        return p;
    }

    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

    return p;
}

int replacenodechildsum(node *root)
{

    if (root == NULL)
    {

        return 0;
    }
    /// for child nodes don't change just return that node data
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    ///post order traversal
    int leftsum = replacenodechildsum(root->left);
    int rightsum = replacenodechildsum(root->right);
    int temp = root->data;
    root->data = leftsum + rightsum;

    return temp + root->data;
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

node *buildtreefromarray(int *arr, int s, int e)
{

    if (s > e)
    {

        return NULL;
    }

    int mid = (s + e) / 2;

    node *root = new node(arr[mid]);
    root->left = buildtreefromarray(arr, s, mid - 1);
    root->right = buildtreefromarray(arr, mid + 1, e);

    return root;
}

node *buildtreeinpreorder(int *in, int *pre, int s, int e)
{

    static int i = 0;
    if (s > e)
    {
        return NULL;
    }

    node *root = new node(pre[i]);

    int index = -1;

    for (int j = s; j <= e; j++)
    {

        if (in[j] == pre[i])
        {
            index = j;
            break;
        }
    }

    i++;
    root->left = buildtreeinpreorder(in, pre, s, index - 1);
    root->right = buildtreeinpreorder(in, pre, index + 1, e);

    return root;
}

int main()
{

    node *root = buildtree();
    printpre(root);
    cout << endl;
    printpost(root);
    cout << endl;
    printinorder(root);
    cout << endl;
    cout << height(root);
    cout << endl;
    printkthlevel(root, 2);
    cout << endl;
    levelorder(root);
    cout << endl;
    bfs(root);
    cout << endl;
    cout << countnodes(root);
    cout << endl;
    cout << sumnodes(root);
    cout << endl;
    cout << diameter(root);
    cout << endl;
    Pair p = fastDiameter(root);
    cout << p.height << endl;
    cout << p.diameter << endl;

    bfs(root);
    cout << endl;
    replacenodechildsum(root);
    bfs(root);
    cout << endl;
    if (isheightbalanced(root).balance)
    {
        cout << "Balanced tree" << endl;
    }
    else
    {
        cout << "Not balanced tree" << endl;
    }

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    node *t = buildtreefromarray(arr, 0, 6);
    bfs3(t);
    cout << endl;
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(in) / sizeof(int);
    node *tt = buildtreeinpreorder(in, pre, 0, 7);
    bfs3(tt);
    return 0;
}
