#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class solution
{

    TreeNode *prev;
    TreeNode *head;
    void binarytreetodll(TreeNode *root)
    {
        if (root == NULL)
            return;
        binarytreetodll(root->left);
        if (prev == NULL)
        {
            head = root;
        }
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        binarytreetodll(root->right);
    }

    TreeNode *buildusingPre()
    {

        int d;
        cin >> d;
        if (d == -1)
            return;
        TreeNode *root = new TreeNode(d);
        root->left = buildusingPre();
        root->right = buildusingPre();

        return root;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
