//rolling hash algo (rabin karp algo):calculate hash for substrings to match..
#include<bits/stdc++.h>
#define ll long long int
#define prime 119
using namespace std;


ll createhashval(string str,int n){ //O(m)

    ll result=0;
    for(int i=0;i<n;i++){
        result+=(ll)(str[i]*(ll)pow(prime,i));
    }

    return result;
}

//O(1)
ll recalculatehash(string str,int oldindex,int newindex,ll oldhash,int patlength){

    ll newhash=oldhash-str[oldindex];
    newhash/=prime;
    newhash+=(ll)(str[newindex]*(ll)(pow(prime,patlength-1)));
    return newhash;
}

bool checkequal(string str1,string str2,int start1,int end1,int start2,int end2){

    if(end1-start1 !=end2-start2){
        return false;
    }

    while(start1<=end1 and start2<=end2){
        if(str1[start1]!=str2[start2]){
            return false;
        }
        start1++;
        start2++;
    }


return true;

}







int main(int argc, char const *argv[])
{
    string str,pat;
    cin>>str>>pat;
    ll pathash=createhashval(pat,pat.length());
    ll strhash=createhashval(str,pat.length());
    for(int i=0;i<=str.length()-pat.length();i++){
        if(pathash==strhash and checkequal(str,pat,i,i+pat.length()-1,0,pat.length()-1)){
            cout<<"Match found at:"<<i<<endl;
            return 0;
    }
    if(i<str.length()-pat.length()){
        strhash=recalculatehash(str,i,i+pat.length(),strhash,pat.length());
    }
    }
    return 0;
}

