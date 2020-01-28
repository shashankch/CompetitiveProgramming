
#include<bits/stdc++.h>
#include<stdio.h>
#define ll long long int
using namespace std;


ll n,m,k;
ll dp[2001][2001][6];

ll f(ll i,ll j,ll *a,ll *b,ll k){

    if(i==n || j==m){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }

    ll res=0;
    if(a[i]==b[j]){
        res=1+f(i+1,j+1,a,b,k);
    }
    else{
        if(k>0){
            res=1+f(i+1,j+1,a,b,k-1);
        }
        res=max(res,f(i,j+1,a,b,k));
        res=max(res,f(i+1,j,a,b,k));
    }
return dp[i][j][k]=res;

}
int main(){




cin>>n>>m>>k;
ll a[n],b[m];
for(ll i=0;i<n;i++){
    cin>>a[i];
}
for(ll i=0;i<m;i++){
    cin>>b[i];
}

    for(ll i=0;i<=2000;i++)
        for(ll j=0;j<=2000;j++)
            for(ll k=0;k<=5;k++)
                dp[i][j][k]=-1;

ll ans=f(0,0,a,b,k);
cout<<ans<<endl;

return 0;
}
