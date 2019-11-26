#include<iostream>
#include<cstring>
using namespace std;


char* duplicatetry(char * str,int i){



    if(strlen(str)==1){
        return str;
    }

    if(str[i]==str[i+1]){
        for(int j=strlen(str);j>i;j--){
            str[j]=str[j-1];
        }
        str[i+1]='*';

        duplicatetry(str,i+2);
    }

    else{
        duplicatetry(str,i+1);
    }




}

string duplicateString(string s,int size, int i){

        if(i==size-1) return s;
            if(s[i]==s[i-1]){
                  s.insert(i,"*");

            }

           return duplicateString(s,size,i+1); // return statement added


        }












void duplicatechar(char *str,int i){


    if(i==strlen(str)-1){
      return ;
    }
    if(str[i]==str[i+1] ){
        int j;
        for(j=strlen(str);j>i;j--){
            str[j]=str[j-1];
        }
        str[i+1]='*';

    }
 duplicatechar(str,i+1);



}



void change(char *inp,char *out,int i,int j)
{
    //base case
    if(inp[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    //out[j]=inp[i];
    out[j]=inp[i];
    if(inp[i]==inp[i+1])
        {

            out[++j]='*';

        }
        change(inp,out,i+1,j+1);
}






int main(){

char str[1000];
cin>>str;
int len=strlen(str);
cout<<duplicatetry(str,len);
//duplicatechar(str,0);
 // for(int i=0;str[i]!='\0';i++){
       // cout<<str[i];
   // }
return 0;
}
