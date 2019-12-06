
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



int intersectionpt(node *head,node *head2)

{
    node *temp1=head;
    node *temp2=head2;

    while(temp2!=NULL){

        temp1=head;
        while(temp1!=NULL){

            if(temp2->data==temp1->data){
                return temp2->data;
            }
            temp1=temp1->next;

        }

        temp2=temp2->next;


    }



    return -1;



}











int main(){


node *head=NULL;
node *head2=NULL;
int n1,n2,data;
cin>>n1;
while(n1--){
    cin>>data;
    insertattail(head,data);
}

cin>>n2;
while(n2--){
    cin>>data;
    insertattail(head2,data);
}
cout<<intersectionpt(head,head2);

return 0;
}
