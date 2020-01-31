#include<iostream>
#include<cstring>
#define ll long long int
using namespace std;

ll patternmatch(string inp,string out){

	ll n=inp.size();
	ll m=out.size();
	ll dp[n+1][m+1];
	for(int i=0;i<=n;i++){
		dp[i][0]=0;
	}
	for(int i=0;i<=m;i++){
		dp[0][i]=0;
	}

	dp[0][0]=1;  // both null character in string and pattern..

	for(int i=1;i<=n;i++){

		for(int j=1;j<=m;j++){

				if(out[j-1]=='*'){
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

				}
				else if(out[j-1]=='?' or inp[i-1]==out[j-1]){
					dp[i][j]=dp[i-1][j-1];
				}
				else
				{
					dp[i][j]=0;
				}

		}



	}
return dp[n][m];
}
int main()
{

	string str,pat;
	cin>>str;
	cin>>pat;
	if(patternmatch(str,pat)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}

	return 0;
}