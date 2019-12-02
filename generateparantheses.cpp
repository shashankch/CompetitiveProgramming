
#include<iostream>
using namespace std;


void generateparantheses(int n,int open,int close,int index,char* out){


        ///base case when reach end of the output array.
        if(index==2*n){

            out[index]='\0';
            cout<<out<<endl;
            return;

        }
         if(close<open){

            out[index]=')';
            generateparantheses(n,open,close+1,index+1,out);


        }

        if(open<n){

                out[index]='(';
                generateparantheses(n,open+1,close,index+1,out);

        }



}

/*
#include <iostream>
using namespace std;

void generateParenthesis(int n, int openB, int closeB, string str) {
    if(closeB == n) {
        cout<<str<<endl;
        return;
    }
    if(openB > closeB) {
        generateParenthesis(n, openB, closeB+1, str+')');
    }
    if(openB < n) {
        generateParenthesis(n, openB+1, closeB, str+'(');
    }
}



*/
int main(){

int n;
char out[100];
cin>>n;
generateparantheses(n,0,0,0,out);


return 0;
}
