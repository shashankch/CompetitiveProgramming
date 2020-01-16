
#include<iostream>
#include<unordered_map>
using namespace std;




int main(){

unordered_map<int,int>mp;
int n,k;
cin>>n>>k;
int arr[n+1];
for(int i=1;i<=n;i++){
    cin>>arr[i];
    mp.insert(make_pair(arr[i],i));
}


int num=n;
int count=0;
while(num>=1 && count!=k){


    int index=mp[num];
    int optimum=n-num+1;
    if(index!=optimum ){
        swap(arr[index],arr[optimum]);
        mp[arr[index]]=index;
        mp[arr[optimum]]=optimum;
       count++;

    }
    num--;
    }



for(int i=1;i<=n;i++)
{

    cout<<arr[i]<<" ";
}


return 0;

}


/*
#include <bits/stdc++.h>
using namespace std;
int main() {
map<int,int> m;
int n,k;
cin>>n>>k;
int a[n+1];
//In order to keep track of indexes and the elements, store elements from 1 to n.
for(int i=1;i<=n;i++)
{
cin>>a[i];
m.insert(make_pair(a[i],i));
// m[a[i]] = i;
}
int count=0,pos;
int j=n;
int i=0;
//
while(count!=k&&j>=1)
{
pos=n-j+1;
int ind=0;
if(m.count(j))
    ind = m[j];
if(pos!=ind)
{

swap(a[pos],a[ind]);
count++;
m[a[pos]] = pos;
m[a[ind]] = ind;
}
j--;
}
for(int i=1;i<=n;i++)
cout<<a[i]<<" ";
return 0;
}

*/
