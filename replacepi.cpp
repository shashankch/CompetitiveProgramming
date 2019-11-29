
#include<iostream>
#include<string>
using namespace std;


string replacepi(string str,int i){


    if(i==str.length()){
        return str;
    }
    string res=replacepi(str,i+1);

    if(str[i]=='p' && str[i+1]=='i'){
       return (res.substr(0,i)+"3.14"+res.substr(i+2));
    }

    else{
        return res;
    }





    /*
    void replacePi(char *in,int i,char *out,int j){
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //Rec Case

    if(in[i]=='p'&&in[i+1]=='i'){
        out[j] = '3';
        out[j+1] = '.';
        out[j+2] = '1';
        out[j+3] = '4';
        replacePi(in,i+2,out,j+4);
        return;
    }
    else{
        out[j] = in[i];
        replacePi(in,i+1,out,j+1);
        return;
    }
}
*/

}
int main(){

    int t;
    cin>>t;

    while(t--){

        string str;
        cin>>str;
       cout<<replacepi(str,0);
        cout<<endl;

    }






return 0;}
