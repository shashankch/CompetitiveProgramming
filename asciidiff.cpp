
#include<iostream>
#include<string>
using namespace std;


int main(){

string ch;

cin>>ch;
int len=ch.length();
int i;

cout<<ch[0];
for(i=1;i<len;i++){

int digit=ch[i]-ch[i-1];
cout<<digit;
cout<<ch[i];




}
return 0;
}
