
#include<iostream>
#include<math.h>
using namespace std;


int stringtoint(string str){

    if(str.length()==1){
        return str[0]-'0';

    }
    double y=stringtoint(str.substr(1));
    double x=str[0]-'0';

    x=x*pow(10,str.length()-1)+y;
    return (int)x;



}

int stringtoint2(string str,int len){


        if(len<0)
            return 0 ;

        int a=stringtoint2(str,len-1);
        int b=a*10+(str[len]-'0');



        return b;






}

int main(){


string str;


cin>>str;
int len=str.length();
cout<<stringtoint(str);
cout<<endl;
cout<<stringtoint2(str,len-1);


return 0;
}
