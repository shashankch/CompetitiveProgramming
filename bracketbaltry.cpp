#include <iostream>
#include<stack>
#define ll long long int
#include<cstring>
using namespace std;
int main(){

string str;
cin>>str;
stack <char> stk;
for(ll i=0;i<str.length();i++){

    if(str[i]=='(' || str[i]=='{' || str[i]=='['){
        stk.push(str[i]);
    }

    if( str[i]==')' ){

            if(stk.empty()){
                cout<<"No";
                break;
            }
            if(stk.top()=='('){
                stk.pop();
                continue;
               }

    }
   if( str[i]=='}' ){
        if(stk.empty()){
                cout<<"No";
                break;
            }
            if(stk.top()=='{'){
                stk.pop();
                continue;
               }


       }
     if( str[i]==']' ){
            if(stk.empty()){
                cout<<"No";
                break;
            }
            if(stk.top()=='['){
                stk.pop();
                continue;
               }




    }
}


if(stk.empty()){
    cout<<"Yes";
}
else{
    cout<<"No";
}




return 0;
}
