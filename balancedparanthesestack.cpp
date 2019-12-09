
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;









int main(){

char str[100];
cin>>str;
stack <char> stk;
for(int i=0;str[i]!='\0';i++){

    if(str[i]=='('){
        stk.push(str[i]);
       }
    else if( str[i]==')'){

        if(stk.empty() || stk.top()!='('){

            cout<<"not balanced";
            break;
           }
           else{
            stk.pop();
           }
    }
}

if(stk.empty()){
    cout<<"bracket are balanced";
}
else{
    cout<<"not balanced";
}




return 0;
}
