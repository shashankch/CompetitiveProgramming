#include<iostream>
#include<unordered_map>
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

/*
another way to create all functions........
class LinkedList{
    node*head;
    node*tail;
public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insert(){
    }
};
*/

void insertathead(node *&head,int data){


     if(head==NULL){
        head = new node(data);
        return;
    }
    node * n=new node(data);
    n->next=head;
    head=n;

}

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
void insertatmiddle(node *&head,int data,int p){

    ///empty list
        if(head==NULL || p==0)
        {
           insertathead(head,data);

        }
        else if(p>length(head)){
            insertattail(head,data);
        }  ///position greater than the length of list then insert at the end..
        else{
        node* temp=head;
        int j=1;
        while(j<p){

            temp=temp->next;
            j+=1;

        }
        node *n=new node(data);
        n->next=temp->next;
        temp->next=n;
        }
}

void buildlist(node *&head){

    int data;
    cin>>data;
    while(data!=-1){

        insertattail(head,data);
       // insertathead(head,data);
        cin>>data;

    }


cout<<endl;
//cout<<length(head)<<endl;


}

void deleteatstart(node*&head){


    if(head==NULL){

        return ;
    }

    node *temp=head;
    head=head->next;
    delete temp;




}

void deleteatend(node *&head){

    if(head==NULL){
        return ;

    }

    node *temp=head;
    node* prev=NULL;
    while(temp->next!=NULL){

        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete temp;
}

void deleteinmid(node*&head,int pos){


    if(head==NULL){
        return ;
    }
    if(pos==1){
        deleteatstart(head);
    }
    else if(pos==length(head)){
        deleteatend(head);
    }
    else{
    int j=1;
    node *temp=head;

    while(j<pos){

        temp=temp->next;
        j+=1;


    }
    node* p=temp->next;
    temp->next=p->next;
    delete p;



    }
    }



void searchiterative(node *head,int data){


    while(head!=NULL){

        if(head->data==data){
            cout<<"element found";
            return;
        }
        head=head->next;

    }


    cout<<"not found";





}



void searchrecur(node *head,int key){

    //base case
    if(head==NULL){

        cout<<"element not found";
        return;
    }

    if(head->data==key){
        cout<<"element found";
        return;
    }

    //recursive case
    searchrecur(head->next,key);

}









void print(node *head){


    while(head!=NULL){

        cout<<head->data<<"->";
        head=head->next;


    }
//cout<<"length:"<<length(head)<<endl;

cout<<endl;



}


istream & operator >> (istream &is,node *&head)
{

    buildlist(head);
    return is;
}

ostream & operator <<(ostream &os,node *head)
{

    print(head);

    return os;


}

void reverseiter(node *&head){

    if(head==NULL){
        return ;

    }

    node *curr=head;
    node *nxt;
    node *prev=NULL;

    while(curr!=NULL){
        nxt=curr->next;
        curr->next=prev;

        prev=curr;
        curr=nxt;

    }


    head=prev;


}

node * reverserecur(node *&head){


    ///base case
    if(head==NULL|| head->next==NULL){
        return head;
    }

    /// recursive case;
    node * smallhead=reverserecur(head->next);
    node *curr=head;
    curr->next->next=curr;
    curr->next=NULL;
    /// node *curr=head; node * prev=NULL; node
    ///



    return smallhead;








}
///runner technique.................
node *  findmidpt(node *head){


    if(head==NULL || head->next==NULL){
        return head;
    }


    node* slow=head;
    /// fast can be equal to head or head next depends on the mid needed in the even length list...
    node *fast=head->next;

    /// this fast not null means current should not be null
    /// fast next not null means next node should not null so that null->next does'nt happen..
    while(fast!=NULL && fast->next!=NULL){

        slow=slow->next;
        fast=fast->next->next;


    }

    return slow;






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

node * mergesortedlist(node *a,node *b){

    if(a==NULL){
        return b;
    }
    else if(b==NULL){
        return a;
    }

    node *c;
    /// compare a and b for smaller element to point temp as head of new list..

    if(a->data<b->data){
        c=a;
        /// pointing the pointer of smallest values to the rest of sorted list.We assume returned by recursion.
        c->next=mergesortedlist(a->next,b);

    }
    else{
        c=b;
                /// pointing the pointer of smallest values to the rest of sorted list.We assume returned by recursion.

        c->next=mergesortedlist(a,b->next);

    }
    /// return original value from the call stack......
return c;
}

bool cycledetect(node *head){


    node *slow=head;
    node *fast=head;

    while(fast!=NULL && fast->next!=NULL){

        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast){

            return true;

        }



    }
return false;

}

void cycleremoval(node* head){

      node *slow=head;
        node *fast=head;
         node *prev;
         while(fast!=NULL && fast->next!=NULL){
            prev=slow;
        fast=fast->next->next;
        slow=slow->next;

        if(slow==fast){

            break;

        }

         }

         slow=head;

         while(slow!=fast){
            prev=fast;
            slow=slow->next;
            fast=fast->next;

         }

         prev->next=NULL;





}

node *getlast(node *root){

    while(root->next!=NULL){
        root=root->next;
    }
    return root;


}

/// O(N) time and space
/// floyd is better algorithm : O(n) time and O(1) space;
bool findcyclehash(node *head){
    node *temp=head;
    /// bool value denotes seen or not and key is address of node *
    unordered_map <node *,bool>m;
    while(temp!=NULL){

        if(m[temp]==true){
                cout<<"cycle is present";

                return true;

        }
        m[temp]=true;
        temp=temp->next;
    }
    return false;
}






int main(){


node * head=NULL;
///node * head2=NULL;
///insertathead(head,data);
///buildlist(head);
///print(head);
///cout<<"enter data and pos:"<<endl;
///int data,pos;
///cin>>data>>pos;
///insertatmiddle(head,data,pos);
///deleteatstart(head);
///deleteatend(head);
///cout<<"enter pos to delet:"<<endl;
///int pos;
///cin>>pos;
///deleteinmid(head,pos);
///print(head);
///int key;
///cin>>key;
///searchiterative(head,key);
///searchrecur(head,key);
///cin>>head>>head2;
///cout<<head<<head2;
///reverseiter(head);
///node *temp=reverserecur(head);
///print(temp);

///head=mergesortedlist(head,head2);
///print(head);
//insertattail(head,20);
//insertattail(head,4);
//insertattail(head,15);
//insertattail(head,10);
//head->next->next->next->next = head;
/*
insertattail(head,1);
insertattail(head,2);
insertattail(head,3);
insertattail(head,4);
insertattail(head,5);
insertattail(head,6);
insertattail(head,7);
node *temp1=head;
while(temp1->data!=3){
    temp1=temp1->next;
}
node *temp2=head;
while(temp2->data!=7){
    temp2=temp2->next;
}
temp2->next=temp1;
cycleremoval(head);
print(head);
//if(cycledetect(head)){

   // cout<<"loop found";

//}
//else{
   // cout<<"not found any loooop..";
//}
*/

node *head2=NULL;
cin>>head;
cout<<head;
node *tail=getlast(head);
tail->next=head->next->next->next;
cout<<head;
findcyclehash(head);



return 0;
}

