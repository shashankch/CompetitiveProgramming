
#include<iostream>
using namespace std;

bool dp[1000][1000];
bool topdsubsetsum(int *arr,int n,int sum){

	if(sum==0) return true;

	if(n==0 and sum!=0) return false;

	if(arr[n-1]>sum){
		dp[n][sum]=topdsubsetsum(arr,n-1,sum);
	}
	else{

		dp[n][sum]=topdsubsetsum(arr,n-1,sum) or topdsubsetsum(arr,n-1,sum-arr[n-1]);
	}


	return dp[n][sum];
	
}

bool bottomdsubsetsum(int n,int sum,int *arr){

	bool dp[n+1][sum+1];

	for(int i=0;i<=n;i++){ 	//target sum is zero
		dp[i][0]=true;
	}
	for(int j=0;j<=sum;j++){  //set is empty
		dp[0][j]=false;
	}

	for(int i=1;i<=n;i++){

		for(int j=1;j<=sum;j++){

			if(arr[i-1]>j){
				dp[i][j]=dp[i-1][j];
			}
			else{
				dp[i][j]=dp[i-1][j] or dp[i-1][j-arr[i-1]];
			}

		}
	}
	return dp[n][sum];

}


bool recursubsetsum(int n,int t,int *arr){

	//base case:
	if(t==0) return true;

	if(n==0 and t!=0) return false;

	//recursive cases
	if(arr[n-1]>t){
		return recursubsetsum(n-1,t,arr);
	}

	else{

		return recursubsetsum(n-1,t,arr) or recursubsetsum(n-1,t-arr[n-1],arr);
	}

}

int main(){

int n,t;
cin>>n>>t;
int *arr=new int [n];
for(int i=0;i<n;i++){
	cin>>arr[i];
}

if(recursubsetsum(n,t,arr)==true){
	cout<<"Yes"<<endl;
}
else{
	cout<<"No"<<endl;
}


if(topdsubsetsum(arr,n,t)==true){
	cout<<"Yes"<<endl;
}
else{
	cout<<"No"<<endl;
}

if(bottomdsubsetsum(n,t,arr)==true){
	cout<<"Yes"<<endl;
}
else{
	cout<<"No"<<endl;
}


	return 0;
}