
#include<iostream>
#include<string>
using namespace std;


string keypad [10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void keypadstrings(string in ,string out,int i,int j){


    if(in.length()==0){

        cout<<out<<",";

        return;
    }

    int digit=in[i]-'0';
    if(digit==1 || digit==0){
        keypadstrings(in,out,i+1,j);
    }

    for(int k=0;k<keypad[digit].length();k++){

        out[j]=keypad[digit][k];
        keypadstrings(in,out,i+1,j+1);


    }

}
int main(){


string in;
string out;
cin>>in;
keypadstrings(in,out,0,0);




return 0;
}
