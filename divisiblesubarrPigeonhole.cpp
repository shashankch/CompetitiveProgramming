
#include<iostream>
#define ll long long int
using namespace std;


ll divisiblesubarr(ll n,ll arr[])

{
ll sum=0;
ll prefixsum[1000005]={0};
prefixsum[0]=1;
for(ll i=0;i<n;i++){
    sum+=arr[i];
    sum%=n;
    sum=(sum+n)%n;
    prefixsum[sum]++;
}

ll ans =0;

for(ll i=0;i<n;i++){

    ///cout<<prefixsum[i]<<" ";
    ll no=prefixsum[i];
    ans+=no*(no-1)/2;


}





    return ans;

}

int main(){

int t;
cin>>t;
ll n,arr[1000005];
while(t--){
  cin>>n;
for(ll i=0;i<n;i++){
    cin>>arr[i];
        }
cout<<divisiblesubarr(n,arr)<<endl;
}

return 0;
}
