#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node(int X) : data(X), left(NULL), right(NULL) {}
};

// there are two methods for dist btw nodes:

//1: dist(a,b)=dist(root,a)+dist(root,b)-2*(root,lca); // subtract repeated dist.
//2: dist(a,b)=dist(lca,a)+dist(lca,b)

///////////////////////////// first method/////////////////////////////

Node *findlca(Node *root, int a, int b, int &dist, int &adist, int &bdist, int level)
{

    if (root == NULL)
    {

        return root;
    }

    if (root->data == a)
    {
        adist = level;
        return root;
    }

    if (root->data == b)
    {

        bdist = level;
        return root;
    }

    Node *left = findlca(root->left, a, b, dist, adist, bdist, level + 1);
    Node *right = findlca(root->right, a, b, dist, adist, bdist, level + 1);

    if (left && right)
    {
        dist = adist + bdist - 2 * level;
        return root;
    }

    if (left != NULL)
    {
        return left;
    }

    return right;
}

int calevel(Node *root, int val, int level)
{

    if (root == NULL)
    {
        return -1;
    }

    if (root->data == val)
    {
        return level;
    }

    int left = calevel(root->left, val, level + 1);
    if (left != -1)
    {
        return left;
    }
}

int caldist(Node *root, int a, int b)
{

    int adist = -1, bdist = -1, dist;

    Node *lca = findlca(root, a, b, dist, adist, bdist, 0);

    if (adist != -1 && bdist != -1)
    {
        return dist;
    }

    if (adist != -1)
    {
        dist = calevel(lca, b, 0);
    }

    if (bdist != -1)
    {
        dist = calevel(lca, a, 0);
    }

    return -1;
}

////////////////////////////////////////Second Method/////////////////////////////////////

Node *callca(Node *root, int a, int b)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == a || root->data == b)
    {
        return root;
    }

    Node *left = callca(root->left, a, b);

    Node *right = callca(root->right, a, b);

    if (left != NULL && right != NULL)
    {
        return root;
    }

    if (left != NULL)
    {
        return callca(root->left, a, b);
    }

    return callca(root->right, a, b);
}

int caldist2(Node *root, int a, int b)
{

    Node *lca = callca(root, a, b);

    int adist = calevel(root, a, 0);
    int bdist = calevel(root, b, 0);

    return adist + bdist;
}

int main()
{

    return 0;
}