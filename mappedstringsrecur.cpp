

#include<iostream>
#include<string>
using namespace std;

char mapping[][27]={"", "A", "B", "C", "D", "E",
        "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R",
        "S", "T", "U", "V", "W", "X", "Y", "Z"};


void mappedstring(string number,string out,int index){

    if(index==number.length()){

        cout<<out<<endl;
     return ;
    }
    /// for single digits and check if not equal to zero..
    if(number[index]!='0'){

        string p=mapping[number[index]-'0'];
        mappedstring(number,out+p,index+1);

    }

    if(index<number.length()-1){

        int num1=number[index]-'0';
        int num2=number[index+1]-'0';
        int res=(num1*10)+num2;
        if(res<=26){
        string p=mapping[res];
        mappedstring(number,out+p,index+2);

        }

    }

}

int main(){

string number;
cin>>number;
mappedstring(number,"",0);

return 0;
}
