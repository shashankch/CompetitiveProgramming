
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/// GENERIC TREE/N-ARY TREE BUILD >>>>>>AT THE END >>>>
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


    int d,n;
    cin>>d>>n;
    node *root=new node(d);
    if(n==0){
        return root;
    }

    if(n==1){

    root->left=buildtree();
    return root;
    }
    else if(n==2){
    root->left=buildtree();
    root->right=buildtree();

    return root;
    }


}

void bfs3(node *root){


    queue<node*>q;
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
void sumkthlevel(node *root,int k,vector<int>&v){


    if(root==NULL){
        return;

    }

    if(k==0){

        //cout<<root->data<<" ";
        v.push_back(root->data);
        return;

    }

    sumkthlevel(root->left,k-1,v);
    sumkthlevel(root->right,k-1,v);
    return;
}

int sumAtLevelK(node *root, int k) {
    if(root==NULL) {
        return 0;
    }
    if(k<=0) {
        return root->data;
    }
    int leftAns = sumAtLevelK(root->left, k-1);
    int rightAns = sumAtLevelK(root->right, k-1);
    return leftAns+rightAns;
}


int main(){
int k;
node *root=buildtree();
cin>>k;
vector<int>v;
int sum=0;
sumkthlevel(root,k,v);
for(int i=0 ;i<v.size();i++){
    sum+=v[i];
}
cout<<sum;

///bfs3(root);
///cout<<sumkthlevel(root);



return 0;
}
/*

class node {
public :
    int noOfChildren ;
    int data ;
    node(int d,int n) {
        data = d ;
        noOfChildren = n ;
        right = left = NULL ;
    }
    node *right ;
    node *left ;
};


node* buildTreeGeneric(node*root){
    int d,n ;
    cin >> d >> n;
    root = new node(d,n);
    if(n==0){
        return root ;
    }
    else if(n==1){
        root->left = buildTreeGeneric(root->left);
        return root ;
    }
    else {
        root->left = buildTreeGeneric(root->left);
        root->right = buildTreeGeneric(root->right) ;
        return root ;
    }
}

////////////////////////////.................>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

class node
{ public:
    int data;
    vector<node*> tree;
    node(int n,int d)
    {
        tree.resize(n);
        data=d;
    }
};

node*buildtree()
{
    int data,child;
    cin>>data>>child;

    node*root=new node(child,data);
    for(int i=0;i<child;i++)
    {
    root->tree[i]=buildtree();
    }

    return root;
}

*/
