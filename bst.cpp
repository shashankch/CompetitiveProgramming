
#include<iostream>
#include<queue>
using namespace std;

class node{

public:
    int data;
    node *left;
    node *right;

    node(int d){

        data=d;
        left=NULL;
        right=NULL;
        }
    };

node * buildbst(node *root,int data){


    if(root==NULL){

        return new node(data);
    }

    if(data<=root->data){

        root->left=buildbst(root->left,data);

    }
    else{

        root->right=buildbst(root->right,data);
    }


return root;
}




node * buildtree(){

    int d;
    cin>>d;
    node *root=NULL;
    while(d!=-1){

        root=buildbst(root,d);
        cin>>d;
    }



    return root;
}



void inorder(node *root){


    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);


}













int main(){

node *root=buildtree();
inorder(root);

return 0;
}
