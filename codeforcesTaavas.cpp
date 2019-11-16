

#include<iostream>
#include<cstring>
#define ll long long
using namespace std;


ll luckyindex(char input[])

{

    ll len=strlen(input);
    ll ans=0;
    ans=(1<<len)-2;

    for(ll i=len-1,pos=0;i>=0;i--,pos++){

        if(input[i]=='7'){
            ans+=(1<<pos);
        }


    }

    return ans+1;



}




int main(){

char input[50];
cin>>input;

cout<<luckyindex(input);




return 0;
}
