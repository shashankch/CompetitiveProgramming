#include<iostream>
#include<cstring>
using namespace std;



template<typename T>
class node{

public:
    string key;
    T value;
    node<T> *next;

    node (string k,T v){
        key=k;
        value=v;
        }


};
template<typename T>
class Hashtable{


    int cs;
    int ts;
    node<T> ** buckets;

    int hashfun(string key){

        int L=key.length();
        int ans=0;
        int p=1; /// 37^0 is 1 inital
        for(int i=0;i<L;i++){

            ans+=key[L-i-1]*p;
            p=p*37;

            p%=ts;
            ans%=ts;


        }


    return ans;
    }


public:
    Hashtable(int ds=7){

        cs=0;
        ts=ds;
        buckets=new node<T>*[ts];

        /// makee all address as null
        for(int i=0;i<ts;i++){
            buckets[i]=NULL;
        }



    }

    void insert(string key,T value){

            int i=hashfun(key);
            node <T> *n=new node <T> (key,value);
            n->next=buckets[i];
            buckets[i]=n;



    }
    ///print it
    void print(){

        for(int i=0;i<ts;i++){
            node<T> *temp=buckets[i];
            cout<<"BUCKET:"<<i<<"-->"<<endl;
            while(temp!=NULL){
                cout<<temp->key<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

    }

    T* search(string key){

            int i=hashfun(key);

            node<T> *temp=buckets[i];


                while(temp!=NULL){

                    if(temp->key==key){
                   return &(temp->value);
                    }
                    temp=temp->next;
                }

                return NULL;

            }


     T* erase(string key){

        ///deletes the node with the given key
        int i=hashfun(key);
        node <T>* temp=buckets[i];

        if(temp==NULL){
            cout<<"key not found"<<endl;
        }
        if(temp->key==key){
            buckets[i]=buckets[i]->next;
            temp->next=NULL;
            delete(temp);
            cs--;
            return &temp->value ;
        }


        node<T> *prev=temp;
        while(temp!=NULL){

            if(temp->key==key){

                prev->next=temp->next;
                delete(temp);
                cs--;
                return &temp->value;
            }

            prev=temp;
            temp=temp->next;
        }


    }








};

