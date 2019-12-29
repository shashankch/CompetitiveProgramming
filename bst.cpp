
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

void bfs(node *root){


    queue<node *>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* fr=q.front();
        if(fr==NULL){
            cout<<endl;
            q.pop();

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

bool searchbst(node *root,int data){

    if(root==NULL){

        return false;
    }

    if(root->data==data){

        return true;
    }

    if(data<=root->data){


        return searchbst(root->left,data);
    }
    else{
        return searchbst(root->right,data);
    }


}

node * deletebst(node *root,int data){


    if(root==NULL){
        return NULL;
    }
    if(data<root->data){

        root->left=deletebst(root->left,data);
        return root;

    }
    else if(data==root->data){

        ///for leaf nodes
        if(root->left==NULL && root->right==NULL){

            delete root;
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){

            node *temp=root->left;
            delete root;
            return temp;

        }
        else if(root->right!=NULL && root->left==NULL){

            node *temp=root->right;
            delete root;
            return temp;
        }
        else{


            node *minright=root->right;
            while(minright->left!=NULL){
                minright=minright->left;
            }

            root->data=minright->data;
            root->right=deletebst(root->right,minright->data);

            return root;



        }



    }

    else{

        root->right=deletebst(root->right,data);
        return root;
    }





}

bool isbst(node *root,int max=INT_MAX,int min=INT_MIN){


    if(root==NULL){
        return true;
    }

    if(root->data>min && root->data<max && isbst(root->left,root->data,min) && isbst(root->right,max,root->data)){

        return true;
    }
    return false;
}

class Linkedpair{

public:
    node *head;
    node *tail;


};

Linkedpair flattentree(node *root){

    Linkedpair lp;

    /// no nodes
    if(root==NULL){

        lp.head=lp.tail=NULL;
        return lp;
    }
    /// leaf node
    if(root->left==NULL && root->right==NULL){

        lp.head=lp.tail=root;

        return lp;

    }

    /// node with left child..
    if(root->left!=NULL && root->right==NULL){

        Linkedpair left=flattentree(root->left);
        left.tail->right=root;
        lp.head=left.head;
        lp.tail=root;

        return lp;

    }
    /// node with right child
    if(root->right!=NULL && root->left==NULL){

        Linkedpair right=flattentree(root->right);
        root->right=right.head;
        lp.head=root;
        lp.tail=right.tail;

        return lp;

    }

    /// node with 2 children
    Linkedpair l=flattentree(root->left);
    Linkedpair r=flattentree(root->right);
    l.tail->right=root;
    root->right=r.head;
    lp.head=l.head;
    lp.tail=r.tail;

    return lp;





}


node *buildbstfrompreorder(int *pre,int s,int e,int len){


        static int k=0;
        if(s>e || k>=len){
            return NULL;
        }

    node *root=new node(pre[k]);
    k++;
    if(s==e){return root;}
    int index;
    for(int i=s;i<=e;i++){

        if(root->data<pre[i]){
            index=i;
            break;
        }
    }

    root->left=buildbstfrompreorder(pre,k,index-1,len);
    root->right=buildbstfrompreorder(pre,index,e,len);


    return root;
    }









int main(){

//node *root=buildtree();

//inorder(root);
//cout<<endl;
//bfs(root);
//cout<<endl;
/*
int data;
cin>>data;
if(searchbst(root,data)){
    cout<<"Present"<<endl;

}
else{
    cout<<"not present"<<endl;
}
int del;
cin>>del;
root=deletebst(root,del);
bfs(root);
cout<<endl;
if(isbst(root)){
    cout<<"yes";
}
else{
    cout<<"no";
}

Linkedpair l=flattentree(root);
node *temp=l.head;
while(temp!=NULL){
    cout<<temp->data<<"-->";
    temp=temp->right;
}
*/
int arr[]={5,3,1,7,6,8};
int arr2[]={10,5,1,7,40,50};
node *temp=buildbstfrompreorder(arr2,0,5,6);
inorder(temp);


return 0;
}

/*
5 3 7 1 6 8 -1
1 3 5 6 7 8
5
3 7
1 6 8

10
not present

*/
