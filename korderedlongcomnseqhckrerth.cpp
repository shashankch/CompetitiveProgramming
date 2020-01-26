
#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long int
using namespace std;


ll n,m,a[2005],b[2005];
ll dp[2005][2005][8];

ll f(ll i,ll j,ll k){

    if(i==n || j==m){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }

    ll res=0;
    if(a[i]==b[j]){
        res=1+f(i+1,j+1,k);
    }
    else{
        if(k>0){
            res=1+f(i+1,j+1,k-1);
        }
        res=max(res,f(i,j+1,k));
        res=max(res,f(i+1,j,k));
    }
return dp[i][j][k]=res;

}
int main(){

    memset(dp,-1,sizeof(dp));

ll k;
cin>>n>>m>>k;
for(ll i=0;i<n;i++){
    cin>>a[i];
}
for(ll i=0;i<n;i++){
    cin>>b[i];
}
ll ans=f(0,0,k);
cout<<ans<<endl;

return 0;
}
