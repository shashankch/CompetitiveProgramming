#include<iostream>

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


node * buildtreefromarray(int *arr,int s,int e){


    if(s>e){

        return NULL;
    }

    int mid=(s+e)/2;

    node *root=new node(arr[mid]);
    root->left=buildtreefromarray(arr,s,mid-1);
    root->right=buildtreefromarray(arr,mid+1,e);


    return root;
}
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

    int n;
    cin>>n;
    node *root=NULL;
    while(n--){
        int d;
        cin>>d;
        root=buildbst(root,d);

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

node *root=NULL;
int t;
cin>>t;
while(t--){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    root=buildtreefromarray(arr,0,n-1);
    printpre(root);

}



return 0;
}



