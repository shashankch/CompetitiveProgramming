
#include<iostream>
#include<string>
using namespace std;






void duplicate2(string s,int i,int n){

    if(i==n){
        return ;
    }

    if(s[i]==s[i+1]){
        return duplicate2(s,i+1,n);
    }
    cout<<s[i];
    duplicate2(s,i+1,n);



}





/// duplicateremove has some problem --->

void duplicateremove(string & str,int len,int i){



    if(i==len-1){
        return ;
    }
    if(str[i]==str[i+1]){

        for(int j=i;j<len-1;j++){
            str[j]=str[j+1];
        }


    }

    duplicateremove(str,len,i+1);





}

void recursion(char *s){
    if(s[0]=='\0'){
        return;
    }
    if(s[0]==s[1]){
        int i=0;
        while(s[i]!='\0'){
            s[i]=s[i+1];
            i++;
        }
       recursion(s);
    }
    recursion(s+1);
}


/* Iterative way snippet..
   int j = 0;

   // Traversing string
   for (int i=1; i<n; i++)
   {
       // If current character S[i]
       // is different from S[j]
       if (S[j] != S[i])
       {
           j++;
           S[j] = S[i];
       }
   }

   // Putting string termination
   // character.
   j++;
   S[j] = '\0';
}

*/
int main(){


string str;
cin>>str;

//duplicateremove(str,str.length(),0);
//cout<<str;
duplicate2(str,0,str.length());

return 0;
}
