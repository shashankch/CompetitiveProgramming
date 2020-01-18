
#include<iostream>
// #include<unordered_map>
#include <map>
using namespace std;


class node{

public:
    char data;
    bool terminal;

    // unordered_map<char,node*>children;
    map<char,node*>children;

    node(char data){

        this->data=data;
        this->terminal=false;

    }

};
class tries{

public :
    node *root;
  //  int count;

    tries(){

        this->root=new node('\0');
       // this->count=0;
    }
    void addword(string str){

        node *temp=root;
        for(int i=0;i<str.length();i++){

            char ch=str[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];

            }
            else{
                node *newnode=new node(ch);
                temp->children[ch]=newnode;
                temp=newnode;

            }
        }
        temp->terminal=true;
    }

};


void print(node *root,string s){

    // if(root==NULL){
    //     return ;
    // }


    if(root->children.empty()){

        // s+=root->data;
        cout<<s<<endl;
        return;
    }


    if(root->terminal){
        //  s+=root->data;
       cout<<s<<endl;
    //    for(auto p:root->children){
    //     print(p.second,s);
    //    }
    //    return;
    }

    // if(root->data!='\0'){
    //     s+=root->data;
    // }
    node *t;
    string w;
    for(auto p=root->children.begin();p!=root->children.end();p++){
        t = root->children[p->first];
        w = s+t->data;
        print(t,w);
    }



}








bool searchprefix(node *root,string str){

    node *temp=root;

    for(int i=0;i<str.length();i++){

        char ch=str[i];
        if(temp->children.count(ch)){
            temp=temp->children[ch];
        }

        else{


            return false;
        }




    }


    print(temp,str);

    return true;



}






int main(){

tries *t=new tries();
int n;
cin>>n;
string arr[n];
for(int i=0;i<n;i++){

    cin>>arr[i];
    t->addword(arr[i]);
}

int q;
cin>>q;

for(int i=0;i<q;i++){

    string temp;
    cin>>temp;
   bool p=searchprefix(t->root,temp);
   if(p==false){
        cout<<"No suggestions"<<endl;
        t->addword(temp);

   }


}

return 0;
}
