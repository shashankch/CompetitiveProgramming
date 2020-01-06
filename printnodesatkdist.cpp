
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

node *buildtreeinpreorder(int *in,int *pre,int s,int e){

    static int i=0;
    if(s>e){
        return NULL;
    }

    node *root=new node(pre[i]);

    int index=-1;

    for(int j=s;j<=e;j++){

        if(in[j]==pre[i]){
            index=j;
            break;
        }
    }

    i++;
    root->left=buildtreeinpreorder(in,pre,s,index-1);
    root->right=buildtreeinpreorder(in,pre,index+1,e);


    return root;
}


void krootdist(node *root,int k){

    if(root==NULL || k<0){
        return ;
    }
    if(k==0){
        cout<<root->data<<" ";
        return ;
    }

    krootdist(root->left,k-1);
    krootdist(root->right,k-1);


}



int kdistnode(node *root,int target,int k){


    if(root==NULL){
        return 0 ;
    }
    if(root->data==target){

        krootdist(root,k);
        return 0;

    }
    int ld=kdistnode(root->left,target,k);

    if(ld!=-1){

        if(ld+1==k){
            cout<<root->data<<" ";
        }
        else{
            krootdist(root->right,k-ld-2);
        }

        return 1+ld;
    }

     int rd=kdistnode(root->right,target,k);

    if(rd!=-1){

        if(rd+1==k){
            cout<<root->data<<" ";
        }
        else{
            krootdist(root->left,k-rd-2);
        }

        return 1+rd;
    }

    return -1;
}

int main(){

int n;
cin>>n;

int pre[n],in[n];
for(int i=0;i<n;i++){
    cin>>pre[i];
}

for(int i=0;i<n;i++){
    cin>>in[i];
}

node *temp=buildtreeinpreorder(in,pre,0,n-1);
int q;
cin>>q;
while(q--){

    int target,k;
    cin>>target>>k;

    kdistnode(temp,target,k);
    cout<<endl;


}


return 0;
}


