
#include<iostream>
#define ll long long int
using namespace std;

///https://www.youtube.com/watch?v=TC6snf6KPdE
bool ispossible(ll n,ll m,ll x,ll y,ll mid){

    ll total=m+(n-mid)*y;
    if(total>=(mid*x)){
        return true;
    }
    return false;


}

ll cbwin(ll n,ll m,ll x,ll y){

  ll s=0;
   ll e=n;
    ll ans=0;
    while(s<=e){

        ll mid=(s+e)/2;

        if(ispossible(n,m,x,y,mid)){
            ans=mid;
            s=mid+1;
        }
        else {

            e=mid-1;
        }


    }
return ans;

}
int main(){
ll n,m,x,y;
/// n students
/// m discount coupons
/// x coupons to win scholarship
/// y coupons to pay for admission
cin>>n>>m>>x>>y;
cout<<cbwin(n,m,x,y);
return 0;
}
