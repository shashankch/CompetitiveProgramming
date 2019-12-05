
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

void reversek(node *&head,ll k){

    if(head==NULL){
        return ;

    }
    node *curr=head;
    node *nxt;
    node *prev=NULL;
    ll i=0;
    while(i<k){


        nxt=curr->next;
        curr->next=prev;

        prev=curr;
        curr=nxt;
        i++;
    }
    ///save head of sublist in the temp node before updating prev node as head node..
    node *temp=head;
    head=prev;
    reversek(curr,k); /// call on the next sublist with curr node already there..
    temp->next=curr; /// now head of the sublist which is now tail now attach to the curr node of the next sublist..
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
cin>>n>>k;
node *head=NULL;
for(ll i=0;i<n;i++){
    cin>>data;
    insertattail(head,data);

}
reversek(head,k);
print(head);

return 0;
}
