
#include<iostream>
#include<algorithm>
using namespace std;

/// complexity: O(2^n) exponential
int fib(int n){

    if(n==0) return 0;
    if(n==1) return 1;

    int ans=fib(n-1)+fib(n-2);

    return ans;

    }
/// here in both states refers to points where program reaches :here it n..because 1 to n(states mostly refers to complexity in dp).
/// memoization (top down approach)
/// complexity: o(n) time for insertion in memo and o(n) :space for call stack..
int memo[1000];
int fibmemo(int n){

    if(n==0) return 0;
    if(n==1) return 1;

    if(memo!=-1) return memo[n];

    int ans=fibmemo(n-1)+fibmemo(n-2);
    memo[n]=ans;

    return ans;

}
/// bottom up approach (pure dp technique)
/// complexity: O(n)
int dpfib(int n)
{

    int dp[1000]={};
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];

}




int main(){

int n;
cin>>n;

for(int i=0;i<=n;i++){
    memo[i]=-1;
}
cout<<fib(n);


return 0;
}
