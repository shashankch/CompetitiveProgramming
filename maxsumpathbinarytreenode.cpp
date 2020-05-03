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

class solution
{

    int mx = INT_MIN;
    int maxpathbtwnode(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }

        int left = maxpathbtwnode(root->left);
        int right = maxpathbtwnode(root->right);

        int a = root->val;  // only root.. when children are -ve
        int b = left + root->val;  // case when path from root to leftsubtree
        int c = right + root->val;// when path from root to rightsubtree.
        int d = left + right + root->val; //when path has root,left,right

        mx = max(a, max(b, max(c, max(d, mx)))); // findmax
        return max(left, max(right, 0)) + root->val; //own contribution..
        // here this is return for subtree root..here you have to return max(left,right)+root
    }
};
// another way..
// max_single = max(max(l, r) + root->data, root->data); //own contribution.
// max_top = max(max_single, l + r + root->data); //all conditions.
// res = max(res, max_top); // find max and store.
int main()
{
    return 0;
}
