#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode
{

public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {

        this.data = data;
    }
    ~TreeNode(){
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
       
    }
};

TreeNode<int> *takeinputlevelwise()
{

    int rootdata;
    cout << "enter root data" << endl;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    while (pendingnodes.size() != 0)
    {
        TreeNode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        cout << "enter no of children" << front->data << endl;
        int numchild;
        cin >> numchild;
        for (int i = 0; i < numchild;i++){
            int childata;
            cout << "enter" << i << "thchild of " << front->data << endl;
            cin >> childata;
            TreeNode<int> *child = new TreeNode<int>(childata);
            front->children.push_back(child);
            pendingnodes.push(child);
        }
    }

    return root;
}

TreeNode<int> *takeinput()
{

    int rootdata;
    cin >> rootdata;

    TreeNode<int> *root = new TreeNode<int>(rootdata);

    int n; // no of children.
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeinput();
        root->children.push_back(child);
    }

    return root;
}

int numnodes(TreeNode<int> *root){

    int ans = 1;
    for (int i = 0; i < root->children.size();i++){
        ans += numnodes(root->children[i]);
    }
    return ans;
}


void deleteTree(TreeNode<int> *root){

    for (int i = 0;i<root->children.size();i++){
        deleteTree(root->children[i]);
    }
    delete root;
}


void preorder(TreeNode<int>*root){

    if(root==NULL){
        return;
    }

    cout << root->data << endl;
    for (int i = 0; i < root->children.size();i++){
        preorder(root->children[i]);
    }
}




void printatlevelkdepth(TreeNode<int> *root,int k){

    if(root==NULL){
        return;
    }

    if(k==0){
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size();i++){
        printatlevelkdepth(root->children[i], k - 1);
    }
}




void printTree(TreeNode<int> *root)
{

    //here base case is not req in generic tree..
    //required edge case
    if (root == NULL)
    {
        return;
    }

    cout
        << root->data << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{

    vector<int> *vp = new vector<int>();
    vector<int> v;

    cout << v.size();
    cout << v.at(9);

    TreeNode<int> *root = new TreeNode<int>(23);
    TreeNode<int> *node = new TreeNode<int>(4);
    root->children.push_back(node);

    return 0;
}