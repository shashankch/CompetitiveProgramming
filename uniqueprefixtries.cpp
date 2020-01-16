

#include<iostream>
#include<unordered_map>
using namespace std;


class node{

public:
    char data;
    bool terminal;
    int cnt;
    unordered_map<char,node*>children;

    node(char data){

        this->data=data;
        this->terminal=false;
        this->cnt=0;
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
                temp->cnt=temp->cnt+1;
            }
            else{
                node *newnode=new node(ch);
                temp->children[ch]=newnode;
                temp=newnode;
                temp->cnt=temp->cnt+1;
            }
        }
        temp->terminal=true;
    }

};

  void uniqueprefixhelper(node *&head,char prefix[],int index){


        if(head==NULL){
            return;
        }

        if(head->cnt==1){

            prefix[index]='\0';
            cout<<prefix<<endl;
            return;

        }
        for(int i=0;i<26;i++){
            if(head->children.count(i+'a')){

                        prefix[index]=i+'a';
                        uniqueprefixhelper(head->children[i+'a'],prefix,index+1);
                }

            }

    }












int main(){

tries *t=new tries();

string arr[]={"zebra","dog","dove","duck","zebras"};
for(int i=0;i<5;i++){

    t->addword(arr[i]);

}

char prefix[26];
uniqueprefixhelper(t->root,prefix,0);








return 0;
}
