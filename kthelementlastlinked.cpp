

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

void buildlist(node *&head){

    int data;
    cin>>data;
    while(data!=-1){

        insertattail(head,data);
       // insertathead(head,data);
        cin>>data;

    }
}


///logic : simple: traverse through list and stop at length-k+1 node.
/// logic2: move fast ktimes and then move both slow and fast by 1steps..n-k..
node * kthnodefromend(node *head,int k){


    if(head==NULL || k==0){
        return head;
    }
    node *fast=head;
    node *slow=head;
    while(k--){
        fast=fast->next;

    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }

    return slow;

}


int main(){

node *head=NULL;
buildlist(head);
int k;
cin>>k;
node *ans=kthnodefromend(head,k);
cout<<ans->data;

return 0;
}
