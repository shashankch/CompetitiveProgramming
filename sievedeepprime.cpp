
#include<iostream>
#define ll long long int
#define N 50000005
using namespace std;




void sieveprime(ll n){


    ll prime[N+1]={0};
    prime[0]=prime[1]=0;
    prime[2]=1;
    for(ll i=3;i<=N;i+=2){
        prime[i]=1;
    }
    for(ll i=3;i<=N;i+=2){

        if(prime[i]){
        for(ll j=i*i;j<=N;j+=2*i){
            prime[i]=0;
        }
    }





}
ll cnt=0;
for(ll i=2;i<=N;i++){

    if(prime[i]){
        cnt++;
        if(cnt==n-1)
    {
        cout<<i;
        break;
    }

    }

}


}



int main(){

ll n;
cin>>n;

sieveprime(n);
return 0;

}
