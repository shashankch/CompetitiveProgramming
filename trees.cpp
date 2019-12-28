
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

node *buildtree(){


    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    node* root=new node(d);
    root->left=buildtree();
    root->right=buildtree();


    return root;
}


void printpre(node *root){      ///top down approach

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printpre(root->left);
    printpre(root->right);
}

void printpost(node *root){  ///bottom up approach

 if(root==NULL){
        return;
    }
    printpre(root->left);
    printpre(root->right);
    cout<<root->data<<" ";







}

void printinorder(node *root){


 if(root==NULL){
        return;
    }


    printpre(root->left);
     cout<<root->data<<" ";
    printpre(root->right);

}

int height(node *root){


    if(root==NULL){
        return 0;
    }


    int ls=height(root->left);
    int rs=height(root->right);

    return max(ls,rs)+1;
}

void printkthlevel(node *root,int k){


    if(root==NULL){
        return;

    }

    if(k==1){

        cout<<root->data<<" ";
        return;

    }

    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
    return;
}

void levelorder(node*root){

    int h=height(root);

    for(int i=1;i<=h;i++){

        printkthlevel(root,i);
        cout<<endl;
    }
    return;
}

void bfs(node *root){


    queue<node*>q;
    q.push(root);

    while(!q.empty()){


        node* fr=q.front();
        cout<<fr->data<<" ";
        q.pop();
        if(fr->left){
        q.push(fr->left);
        }
        if(fr->right){
        q.push(fr->right);
        }
    }

    return;

}










int main(){


node* root=buildtree();
printpre(root);
cout<<endl;
printpost(root);
cout<<endl;
printinorder(root);
cout<<endl;
cout<<height(root);
cout<<endl;
printkthlevel(root,2);
cout<<endl;
levelorder(root);
cout<<endl;
bfs(root);
return 0;
}
