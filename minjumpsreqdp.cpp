
#include <bits/stdc++.h>
using namespace std;


int dp[1001];
int minjumps(int n,int *arr,int i){

	if(i==n-1){
		return dp[i]=0;
	}

	if(dp[i]!=-1) return dp[i];

	int steps=INT_MAX;
	if(arr[i]==0) return INT_MAX-5;

	for(int jump=1;jump<=arr[i] and (i+jump)<n;jump++){

		steps=min(steps,1+minjumps(n,arr,i+jump));
	}

	return dp[i]=steps;
}

int main(int argc, char const *argv[])
{
	

	int t,n;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof(dp));
		cin>>n;

		int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cout<<minjumps(n,arr,0)<<endl;


	}




	return 0;
}