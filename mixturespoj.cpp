
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll a[1000];
ll dp[1000][1000];


ll sum (ll s,ll e){

    ll ans=0;

    for(ll i=s;i<=e;i++){
        ans+=a[i];
        ans%=100;
    }

    return ans;

}




ll solvemixtures(ll i,ll j){

    ///base case
    if(i>=j){
        return 0;
    }

    /// if the answer already there
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    /// break expression at every possible k

    dp[i][j]=INT_MAX;
    for(ll k=i;k<=j;k++){
        dp[i][j]=min(dp[i][j],solvemixtures(i,k)+solvemixtures(k+1,j)+sum(i,k)*sum(k+1,j));
    }

    return dp[i][j];


}


int main(){

ll n;
//while((scanf("%d",&n))!=EOF){
cin>>n;

        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

    /// initialize dp with -1
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        cout<<solvemixtures(0,n-1);


 //}



return 0;
}
