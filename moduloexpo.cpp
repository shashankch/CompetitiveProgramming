

#include<iostream>
#define ll long long int
using namespace std;



ll modulobyrecursion(ll a,ll b,ll c){


if(b==0) return 1;
if(a==0) return 0;

ll temp=modulobyrecursion(a,b/2,c);
if(b%2==0){

    return (temp*temp)%c;

}
else
    return (a*temp*temp)%c;



}




ll modulobybitmask(ll a,ll b, ll c){

    ll res=1;

    while(b!=0){

        if(b&1){

            res=(res*a)%c;
        }
        a=(a*a)%c;
        b=b>>1;


    }



return res;


}





int main(){

ll a,b,c;
cin>>a>>b>>c;
cout<<modulobyrecursion(a,b,c);



return 0;
}
