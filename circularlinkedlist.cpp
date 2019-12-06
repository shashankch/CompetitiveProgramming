
#include<iostream>
using namespace std;



class node{


public:
    int data;
    node * next;

    node(int d){

    data=d;
    next=NULL;
    }

};


node *getNode(node *head,int data){


    node *temp=head;
    while(temp->next!=head && temp!=NULL){

        if(temp->data==data){
            return temp;
        }
        temp=temp->next;

    }
    if(temp->data==data) return temp;
    else return NULL;

}


void deletenode(node *&head,int data){

    node * del=getNode(head,data);

    if(del==NULL){
        cout<<"node not present";
        return;
    }
    if(head==del){

        head=del->next;
        node *t=head;
        while(t->next!=head){
            t=t->next;
        }
        t->next=head;
        delete del;
    }
     node *temp=head;
    while(temp->next!=del){
            temp=temp->next;
        }

        temp->next=del->next;
        delete del;
}

///insert at head....
void push(node *&head,int data){


    node *temp=head;

    node *n=new node(data);
    n->next=head;
    if(head!=NULL){

        while(temp->next!=head){

            temp=temp->next;

        }
        temp->next=n;



}
    else{

        n->next=n;

    }
    head=n;

}

void print(node *head){

    node *temp=head;
    while(temp->next!=head){

        cout<<temp->data<<"-->";
        temp=temp->next;
    }
    cout<<temp->data<<"end";

}






int main(){

node *head=NULL;
push(head,1);
push(head,2);
push(head,3);
push(head,4);
push(head,5);
print(head);
deletenode(head,3);
print(head);
return 0;
}

