


#include<iostream>
using namespace std;


char alpha[][10]={"zero","one", "two","three","four","five","six","seven","eight","nine"};

void printdigit(int n){

if(n==0) return ;

printdigit(n/10);
cout<<alpha[n%10]<<" ";
}










int main(){

int n;
cin>>n;

printdigit(n);

return 0;
}
