
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

void insertattail(node*&head,int data){


        if(head==NULL){
        head = new node(data);
        return;
    }
      node *tail=head;
      while(tail->next!=NULL){

            tail=tail->next;


      }
      tail->next=new node(data);
      return;



}

int length(node*head){

    int len=0;
    while(head!=NULL){
        head = head->next;
        len += 1;
    }
    return len;
}

void print(node *head){


    while(head!=NULL){

        cout<<head->data<<"->";
        head=head->next;


    }
//cout<<"length:"<<length(head)<<endl;

cout<<endl;



}


node *  findmidpt(node *head){


    if(head==NULL || head->next==NULL){
        return head;
    }


    node* slow=head;

    node *fast=head->next;


    while(fast!=NULL && fast->next!=NULL){

        slow=slow->next;
        fast=fast->next->next;


    }

    return slow;






}

node * mergesortedlist(node *a,node *b){

    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }

    node *c;


    if(a->data<b->data){
        c=a;

        c->next=mergesortedlist(a->next,b);

    }
    else{
        c=b;


        c->next=mergesortedlist(a,b->next);

    }

return c;
}

node *mergesorting(node *head){


        if(head==NULL || head->next==NULL){

            return head;
        }

        node *mid=findmidpt(head);
        node *a=head;
        node *b=mid->next;
        mid->next=NULL;

    a=mergesorting(a);
    b=mergesorting(b);

    node *c=mergesortedlist(a,b);


    return c;



}












int main(){

int n,data;
node *head=NULL;
cin>>n;
while(n--){

    cin>>data;
    insertattail(head,data);


}

node *ans=mergesorting(head);
print(ans);

return 0;
}











