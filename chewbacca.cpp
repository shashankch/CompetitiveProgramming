
#include<iostream>
#include<string>
using namespace std;







int main(){
char n[1000];
cin>>n;

int i=0;
   if(n[i]=='9'){i++;}

for(;n[i]!='\0';i++){
    int digit=n[i]-'0';
     if(digit>=5){


        digit=9-digit;
        n[i]=digit+'0';
    }
}

cout<<n;




return 0;
}
