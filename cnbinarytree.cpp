#include <bits/stdc++.h>
using namespace std;














template <typename T>
class binarytreenode
{

public:
    T data;
    binarytreenode *left;
    binarytreenode *right;

    binarytreenode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binarytreenode()
    {

        delete left;
        delete right;
    }
};

void printtree(binarytreenode<int> *root){

    if(root==NULL){
        return;
    }
    cout << root->data << endl;
    printtree(root->left);
    printtree(root->right);
}
void printtree2(binarytreenode<int> *root)
{

    if (root == NULL)
    {
        return;
    }
    cout << root->data << ":" ;
    if(root->left!=NULL){

        cout << "L" << root->left->data;
    }
    if(root->right){
        cout << "R" << root->right->data;
    }
    cout << endl;
    printtree(root->left);
    printtree(root->right);
}

binarytreenode<int> *takeinput(){

    int rootdata;
    cout << "enter data" << endl;
    cin >> rootdata;
    if(rootdata==-1){
        return NULL;
    }

    binarytreenode<int> *root = new binarytreenode<int>(rootdata);
    binarytreenode<int> *leftchild = takeinput();
    binarytreenode<int> *rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;

    return root;
}

binarytreenode<int> *takeinputlevel(){
    int rootdata;
    cin >> rootdata;
    if(rootdata==-1){
        return NULL;
    }

    binarytreenode<int> *root = new binarytreenode<int>(rootdata);
    queue<binarytreenode<int> *> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0){
        binarytreenode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        int leftchild;
        cin >> leftchild;
        if(leftchild!=-1){
            binarytreenode<int> *child = new binarytreenode<int>(leftchild);
            front->left = child;
            pendingnodes.push(child);
        }
        int rightchild;
        cin >> rightchild;
        if (rightchild != -1)
        {
            binarytreenode<int> *child = new binarytreenode<int>(rightchild);
            front->right = child;
            pendingnodes.push(child);
        }
    }

    return root;
}

int height(binarytreenode<int>*root){

    if(root==NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));


}

pair<int,int> heightdiameter(binarytreenode<int> *root){

        if(root==NULL){

            pair<int, int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }

        pair<int, int> leftans = heightdiameter(root->left);
        pair<int, int> rightans = heightdiameter(root->right);

        int ld = leftans.first;
        int lh = leftans.second;
        int rd = rightans.first;
        int rh = rightans.second;

        int height = 1 + max(lh, rh);
        int diameter = max(lh + rh, max(ld, rd));

        pair<int, int> ans;
        p.first = height;
        p.second = diameter;

        return p;

}












int diameter(binarytreenode<int> *root){

    if(root==NULL){
        return 0;
    }

    int a = height(root->left) + height(root->right);
    int b = diameter(root->left);
    int c = diameter(root->right);

    return max(a, max(b, c));


}








int numnodes(binarytreenode<int> *root)
{

   if(root==NULL)
       {return 0;

}

return 1 + numnodes(root->left) + numnodes(root->right);
}

int main(int argc, char const *argv[])
{

    binarytreenode<int> *root = new binarytreenode<int>(1);

    binarytreenode<int> *node1 = new binarytreenode<int>(3);
    binarytreenode<int> *node2 = new binarytreenode<int>(4);
    root->left = node1;
    root->right = node2;
    binarytreenode<int> *root = takeinput();
    printtree2(root);
    /* code */
    return 0;
}
