#include<iostream>
#define MX 100005
using namespace std;
int reset[MX];


void kmppreprocess(string pat){
    int i=0,j=1;
    reset[0]=-1;
    while(i<pat.size()){
        //check for resetting
        while(j>=0 and pat[i]!=pat[j]){
            j=reset[j];
        }
        i++;
        j++;
        reset[i]=j;
    }

}

void kmpsearch(string str,string pat){
    kmppreprocess(pat);
    int i=0,j=0;
    while(i<str.size()){
        while(j>=0 and str[i]!=pat[j]){
            j=reset[j];
        }
        i++;
        j++;
        if(j==pat.size()){
            cout<<"Pattern found at:"<<i-j<<endl;
            j=reset[j];
        }
    }
}

int main(){

for(int i=0;i<MX;i++){
    reset[i]=-1;
}
string str,pat;
cin>>str>>pat;
kmpsearch(str,pat);


    return 0;
}