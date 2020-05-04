#include <bits/stdc++.h>
using namespace std;

//single traversal O(N)
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class custom
{

public:
    bool hasKey1;
    bool hasKey2;
    TreeNode *node;
};

custom *helper(TreeNode *root, TreeNode *p, TreeNode *q)
{

    if (root == NULL)
    {
        return NULL;
    }
    //here node is storing the lca of p and q..
    // here it means found p and q 's ancestor in leftsubtree
    custom *left = helper(root->left, p, q);
    if (left != NULL && left->node != NULL)
    {
        return left;
    }
    // here it means found p and q 's ancestor in rightsubtree
    custom *right = helper(root->right, p, q);
    if (right != NULL && root->val != NULL)
    {
        return right;
    }
    // here it means p and q are present in left and right subtree respectively.
    // so root will be the lca ..
    custom *result = new custom();

    if (left != NULL and right != NULL)
    {

        result->node = root;
        result->hasKey1 = true;
        result->hasKey2 = true;

        return result;
    }

    else if (root->val == p->val)
    {
        result->hasKey1 = true;
        result->hasKey2 = (left) ? left->hasKey2 : false or (right) ? right->hasKey2 : false;
        return result;
    }

    else if (root->val == q->val)
    {
        result->hasKey2 = true;
        result->hasKey1 = (left) ? left->hasKey1 : false or (right) ? right->hasKey1 : false;
        return result;
    }
    else if (left)
    {
        return left;
    }
    else if (right)
    {
        return right;
    }
    return NULL;
}

TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
{
    custom *result = helper(root, p, q);
    if (result == NULL)
        return NULL;

    else
    {
        return result->node;
    }
}

bool findpathfrmrootnode(TreeNode *root, int node, vector<int> &path)
{

    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->val);

    if(root->val==node){
        return true;
    }

    if(root->left!=NULL && findpathfrmrootnode(root->left,node,path))
    {
        return true;
    }
    if(root->right!=NULL && findpathfrmrootnode(root->right,node,path)){
        return true;
    }

    path.pop_back();
    return false;

}

int main()
{

    return 0;
}