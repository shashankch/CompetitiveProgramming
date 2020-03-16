#include<iostream>
#include<cstring>
#include<string>

#include<algorithm>
using namespace std;


void removeduplicates(char a[]){

    int l=strlen(a);
    if(l==1 or l==0){

        return ;
    }

    int prev=0;
    for(int current=1;current<l;current++){

            if(a[current]!=a[prev]){
                prev++;
                a[prev]=a[current];
            }


    }


    a[prev+1]='\0';
    return; 



}














int main(){

////////////////////////////////////////

// string str;
// cin.getline(str.c_str,1000);

// char ch[100];


// cin.getline(ch,100,',');

// string::iterator it;


// string str[100];

// string str="hello";
// string b="world";
// string str(b);
// string a=b;
// a+=str;
// a.append("bye");
// string s="hey whats up";
// int index=1;
// int len=4;
// s.erase(index,len+1);
// int l=s.length();
// s.substr(index,len);

// if(s.compare("bb")){
//     // == 0, a>b --+ve else -ve
// }
// int n;
// cin>>n;
// cin.get();
// string str[100];
// for(int i=0;i<n;i++){
//     getline(cin,str[i]);
// }

//////////////////////////////////////////////////////////////

char a[1000];
cin.getline(a,1000);

removeduplicates(a);







    return 0;
}
