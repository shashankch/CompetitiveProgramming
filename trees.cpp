
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


///using queue..
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
///using queue with pair --node * and int level...
///void bfs2()...


///using char null marker...
void bfs3(node *root){


    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){


        node* fr=q.front();
        if(fr==NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{

        cout<<fr->data<<" ";
        q.pop();
        if(fr->left){
        q.push(fr->left);
        }
        if(fr->right){
        q.push(fr->right);
        }
    }
    }
    return;

}

int countnodes(node *root){

    if(root==NULL){

        return 0;
    }

    return 1+countnodes(root->left)+countnodes(root->right);



}


int sumnodes(node *root){

    if(root==NULL){

        return 0;
    }

    return root->data+sumnodes(root->left)+sumnodes(root->right);



}

int diameter(node *root){


    if(root==NULL){
        return 0;
    }

    int h1=height(root->left);
    int h2=height(root->right);

    int d1=h1+h2;
    int d2=diameter(root->left);
    int d3=diameter(root->right);

    return max(d1,max(d2,d3));

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
cout<<endl;
cout<<countnodes(root);
cout<<endl;
cout<<sumnodes(root);
cout<<endl;
cout<<diameter(root);
return 0;
}
