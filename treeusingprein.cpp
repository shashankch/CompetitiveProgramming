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


    int j=0;


    for( j=s;j<=e;j++){

        if(in[j]==pre[i]){

            break;
        }
    }

    i++;
    root->left=buildtreeinpreorder(in,pre,s,j-1);
    root->right=buildtreeinpreorder(in,pre,j+1,e);


    return root;
}

void print(node *root)
{
    if(root==NULL)
      return;
    if(root->left!=NULL && root->right!=NULL)
    {
        cout<<root->left->data;
        cout<<" => ";
        cout<<root->data;
        cout<<" <= ";
        cout<<root->right->data;
        cout<<endl;
    }
    if(root->left!=NULL && root->right==NULL)
    {
        cout<<root->left->data;
        cout<<" => ";
        cout<<root->data;
        cout<<" <= END";
        cout<<endl;

    }
    if(root->left==NULL && root->right!=NULL)
    {
        cout<<"END =>";
        cout<<root->data;
        cout<<" <= ";
        cout<<root->right->data;
        cout<<endl;
    }
    if(root->left==NULL && root->right==NULL)
    {
        cout<<"END => ";
        cout<<root->data;
        cout<<" <= END";
        cout<<endl;

    }
    print(root->left);
    print(root->right);
}
int main(){


int n,m;
cin>>n;
int pre[1001];
for(int i=0;i<n;i++){

    cin>>pre[i];
}
cin>>m;
int in[1001];
for(int i=0;i<m;i++){
    cin>>in[i];
}
node *temp=buildtreeinpreorder(in,pre,0,m-1);
print(temp);



return 0;}
