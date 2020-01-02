#include<iostream>
#include<climits>
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

class info{

public:
    int maxv;
    int minv;
    bool b;
   int ans;
    int s;




};



info largestbst(node *temp){


    if(temp==NULL){

        return {INT_MIN,INT_MAX,true,0,0};

    }
    if(temp->left==NULL&& temp->right==NULL){

        return {temp->data,temp->data,true,1,1};
    }

    info l=largestbst(temp->left);
    info r=largestbst(temp->right);

    info curr;
    curr.s=(l.s+r.s)+1;

    if(l.b && r.b && l.maxv<temp->data && r.minv>temp->data){

        curr.minv=(l.minv,min(r.minv,temp->data));
        curr.maxv=(r.maxv,max(l.maxv,temp->data));


        curr.ans=curr.s;
        curr.b=true;
        return curr;


    }

    curr.ans=max(l.ans,r.ans);
    curr.b=false;

    return curr;


}
int main(){

int n;
cin>>n;
int pre[1001];
for(int i=0;i<n;i++){
    cin>>pre[i];
}
int in[1001];
for(int i=0;i<n;i++){
    cin>>in[i];
}
node *temp=buildtreeinpreorder(in,pre,0,n-1);
info res=largestbst(temp);
cout<<res.ans;

return 0;
}
