
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
void printpre(node *root){      ///top down approach

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printpre(root->left);
    printpre(root->right);
}



void replacenodechildsum(node *root,int *sum){

    if(root==NULL){

        return ;
    }

    replacenodechildsum(root->right,sum);
    *sum=*sum+root->data;
    root->data=*sum;
    replacenodechildsum(root->left,sum);
}
void replacesumhelper(node *root){

int sum=0;
replacenodechildsum(root,&sum);

}


int main(){

int n;
int arr[1001];

cin>>n;
for(int i=0;i<n;i++){

    cin>>arr[i];

}
node *temp=buildtreefromarray(arr,0,n-1);
replacesumhelper(temp);
printpre(temp);
return 0;
}
