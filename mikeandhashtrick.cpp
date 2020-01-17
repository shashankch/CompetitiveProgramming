
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int* hash_array(int A[], int n,int MAX)
{

    int* hash = new int[MAX+1]; //MAX is the maximum possible value of A[i]
    for(int i=0;i<=MAX;i++) hash[i]=-1; //initialize hash to -1.
    int count = 0;
    for(int i=0;i<n;i++) // Loop through elements of array
    {
        if(hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            continue;
        }
        for(int j = 0;j<i;j++)
        {
            if(hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
    }
    return hash;
}



int main(){


int n;
cin>>n;
map<int,vector<int> > m;
int arr[n];
  int MAX=0;
for(int i=0;i<n;i++){

   cin>>arr[i];
    if(arr[i]>MAX){
            MAX=arr[i];
    }

}


int *has=hash_array(arr,n,MAX);
for(int i=0;i<=MAX;i++){
    if(has[i]!=-1){
        m[has[i]].push_back(i);
    }
}
for(auto v:m){

    for(int i=0;i<v.second.size();i++){
        cout<<v.second[i]<<endl;
    }

}


return 0;
}
/*
#include <bits/stdc++.h>
#define ff first
#define se second
#define pb push_back
#define nn 100100
#define ll long long int

using namespace std;
​
map<int, int>last; //stores the last position of every integer that occurred in the array.
int a[nn];
​
bool compare(int a,int b) //sorting by last position
{
    return last[a]<last[b];
}
​
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(last.find(a[i])==last.end())
            v.pb(a[i]);
        last[a[i]]=i;
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}


*/


/*
#include<iostream>
using namespace std;

const int MAX = 1000000000;

int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int fre[MAX] = {0};
	int store[n];

	for(int i = 0; i < n; i++) {
		store[i] = -1;
	}

	for(int i = n - 1; i >= 0; i--) {
		if(fre[arr[i]] == 0) {
			store[i] = 0;
		}
		fre[arr[i]]++;
	}

	for(int i = 0; i < n; i++) {
		if(store[i] == 0) {
			cout << arr[i] << endl;
		}
		//cout << store[i] << " ";
	}
}

*/
