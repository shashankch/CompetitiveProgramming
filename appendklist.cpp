


#include<iostream>
#define ll long long int
using namespace std;

class node{


public:
    ll data;
    node * next;

    node(ll d){

    data=d;
    next=NULL;
    }

};
int length(node*head){

    int len=0;
    while(head!=NULL){
        head = head->next;
        len += 1;
    }
    return len;
}
void insertattail(node*&head,ll data){


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


void appendk(node *&head,ll k){


     if(head==NULL){

        return ;
    }
    if(k>=length(head)){
        k=k%length(head);
    }
    if(k%length(head)==0){
        return;
    }
    node *fast=head;
    node *slow=head;
    while(k--){
        fast=fast->next;

    }
    node *prev;
    while(fast!=NULL){
            prev=slow;
        slow=slow->next;
        fast=fast->next;
    }
    node *mainhead=head;
    head=slow;
    node *temp=slow;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=mainhead;
   prev->next=NULL;









}




void print(node *head){


    while(head!=NULL){

        cout<<head->data<<" ";
        head=head->next;


    }


cout<<endl;



}


int main(){

ll n,k,data;
cin>>n;
node *head=NULL;
for(ll i=0;i<n;i++){
    cin>>data;
    insertattail(head,data);

}
cin>>k;
appendk(head,k);
print(head);

return 0;
}
