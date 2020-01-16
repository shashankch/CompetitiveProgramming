
#include<iostream>
#include<unordered_map>
using namespace std;


class node{

public:
    char data;
    bool terminal;
    unordered_map<char,node*>children;

    node(char data){

        this->data=data;
        this->terminal=false;
    }

};

class tries{

public :
    node *root;
    int count;

    tries(){

        this->root=new node('\0');
        this->count=0;
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
    bool searchword(string str){

        node *temp=root;
        for(int i=0;i<str.size();i++){
            char ch=str[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }
            else{

                return false;
            }


        }

        return temp->terminal;
    }

};












int main(){

int t;
cin>>t;
tries tt;
while(t--){

    string str;
    cin>>str;
    tt.addword(str);

}

int q;
cin>>q;
while(q--){

    string str;
    cin>>str;
    cout<<tt.searchword(str)<<endl;

}







return 0;
}
