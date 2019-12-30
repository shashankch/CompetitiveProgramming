

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

node *buildtree(string exist){

    if(exist=="true"){

        int d;
        cin>>d;
        node *root=new node(d);
        string lt;
        cin>>lt;
        if(lt=="true"){
            root->left=buildtree(lt);
        }
        string rt;
        cin>>rt;
        if(rt=="true"){
            root->right=buildtree(rt);
        }



       return root;


    }

    return NULL;




}

bool isidentical(node *a,node *b){

        if(a==NULL && b==NULL){
            return true;
        }

        if(a!=NULL && b!=NULL){

        bool left=isidentical(a->left,b->left);
        bool right=isidentical(a->right,b->right);
        return left && right;
        }
        return false;
}


int main(){
 node *a=buildtree("true");
 node *b=buildtree("true");
    if(isidentical(a,b)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }


return 0;
}
