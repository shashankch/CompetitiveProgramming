
#include<iostream>
#include "hashtable.h"
using namespace std;

 int main(){


    Hashtable <int>h(7);
    h.insert("Mango",100);
     h.insert("apple",200);
      h.insert("guava",300);
      h.insert("banana",250);
       //h.insert("chikeu",400);
h.print();
/*
int *price=h.search("banana");
 if(price==NULL){
    cout<<"not found";
 }
 else{
    cout<<"price is:"<<*price;
 }
cout<<endl;
 int *deletedprice=h.erase("chikeu");
 cout<<"deleted item price is:"<<*deletedprice<<endl;
h.print();

*/

    h["litchi"]=120;    ///insert;
    h["Mango"]=800; ///update;
    cout<<h["Mango"]<<endl; ///search functionality
h.print();
 return 0;
 }
