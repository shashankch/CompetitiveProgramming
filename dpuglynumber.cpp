#include <iostream>
#define ll long long int
using namespace std;


ll printnthseq(ll n){

	ll dp[n];
	dp[0]=1;

	ll i2=0,i3=0,i5=0;
	ll u2=2,u3=3,u5=5;

	for(ll i=1;i<n;i++){

		ll res=min(u2,min(u3,u5));
		dp[i]=res;

		if(res==u2){
			i2++;
			u2=dp[i2]*2;
		}
		if(res==u5){
			i5++;
			u5=dp[i5]*5;
		}
		
		if(res==u3){
			i3++;
			u3=dp[i3]*3;
		}
	}
	return dp[n-1];
}

int main(int argc, char const *argv[])
{
	
	ll t;
	cin>>t;
	while(t--){

		ll n;
		cin>>n;
		cout<<printnthseq(n)<<endl;
	}





	return 0;
}