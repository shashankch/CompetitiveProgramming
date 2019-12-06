
#include<iostream>
using namespace std;


class node {
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







void print(node *head){


    while(head!=NULL){

        cout<<head->data<<" ";
        head=head->next;


    }
//cout<<"length:"<<length(head)<<endl;

cout<<endl;



}

node *evenodd(node *&evenhead,node*&oddhead){

    node *finalhead;
    if(evenhead==NULL){
        finalhead=oddhead;
        return finalhead;
    }
    else if(oddhead==NULL){
        finalhead=evenhead;
         return finalhead;
    }
    else{

        node *temp=oddhead;
        while(temp->next!=NULL){

            temp=temp->next;

        }

        temp->next=evenhead;


    }


    return oddhead;



}




int main(){

int n,data;
cin>>n;
node *oddhead=NULL;
node *evenhead=NULL;
while(n--){
        cin>>data;
        if(data &1){
    insertattail(oddhead,data);
        }
        else{
            insertattail(evenhead,data);
        }
}
node *finalhead=evenodd(evenhead,oddhead);
print(finalhead);

return 0;}
