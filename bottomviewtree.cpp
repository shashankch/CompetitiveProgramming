
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

    queue<node *>q;
    int d;
    cin>>d;
   node *root=new node(d);
   q.push(root);
   while(!q.empty()){

        node *temp=q.front();
        q.pop();
        int l,r;
        cin>>l>>r;

        if(l!=-1){

            temp->left=new node(l);
            q.push(temp->left);
        }
        if(r!=-1){

            temp->right=new node(r);
            q.push(temp->right);

        }
    }

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

int main(){


node *root=buildtree();
printpre(root);



return 0;

}

