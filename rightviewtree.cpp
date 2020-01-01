

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



void rightviewhelp(node *root,int level,int &ml){

    if(root==NULL){
        return;
    }

    if(level>ml){

        cout<<root->data<<" ";
        ml=level;
    }

    rightviewhelp(root->right,level+1,ml);
    rightviewhelp(root->left,level+1,ml);
}


void rightview(node *root){

   int mxl=0;
    rightviewhelp(root,1,mxl);


}

int main(){


node *root=buildtree();
rightview(root);


return 0;

}

