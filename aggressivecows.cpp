
#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;

///https://www.youtube.com/watch?v=TC6snf6KPdE
bool ispossible(ll arr[],ll n,ll k,ll ans){


ll cows=1;
ll prev=arr[0];
for(ll i=1;i<n;i++){
        if((arr[i]-prev)>=ans){
            prev=arr[i];
            cows++;
        if(cows==k){
            return true;
            }
    }


}
if(cows<k)return false;
return true;
}

ll cowsdist(ll arr[],ll n,ll c){

  ll s=0;
   ll e=arr[n-1];
    ll ans=0;
    while(s<=e){

        int mid=(s+e)/2;

        if(ispossible(arr,n,c,mid)){
            ans=mid;
            s=mid+1;
        }
        else {
            ///false condition when placement is not possible for cows.
            e=mid-1;
        }


    }
return ans;

}
int main(){
ll n,c;
ll arr[10005];
cin>>n>>c;
for(ll i=0;i<n;i++){
cin>>arr[i];
}
sort(arr,arr+n);
cout<<cowsdist(arr,n,c);
return 0;
}
