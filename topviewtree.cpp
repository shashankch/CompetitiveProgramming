
#include<iostream>
#include<queue>
#include<map>
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



void topview(node *root,int hd,map<int,int> &mp){

    if(root==NULL){
        return;
    }

    if(mp.count(hd)==0 ){

        mp[hd]=root->data;
    }
    topview(root->left,hd-1,mp);
    topview(root->right,hd+1,mp);
}


void top(node *root){

    map<int,int>mp;

    topview(root,0,mp);

     for(auto i=mp.begin();i!=mp.end();i++)
    {
        cout<<i->second<<" ";
    }



}

int main(){


node *root=buildtree();
top(root);


return 0;

}

