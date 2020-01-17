
#include<iostream>
#include<unordered_set>
using namespace std;

int main(){


int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
unordered_set<int>mp;

int ans=0;
int j=0;
for(int i=0;i<n;i++){

    while(j<n and mp.find(arr[j])==mp.end()){
        mp.insert(arr[j]);
        j++;
    }

    ans+=((j-i)*(j-i+1))/2;
    mp.erase(arr[i]);
}

cout<<ans%1000000007;

return 0;
}
