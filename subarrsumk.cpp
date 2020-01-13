


#include<iostream>
#include<unordered_map>
using namespace std;


int longestsubsumk(int *arr,int n,int k){

    unordered_map<int,int>m;
    int pre=0;
    int longest=0;
    for(int i=0;i<n;i++){
        pre+=arr[i];
       // if(arr[i]==0 and longest==0) longest=1;
        if(pre==k) longest=max(longest,i+1);
        if(m.find(pre-k)!=m.end()){
            longest=max(longest,i-m[pre-k]);
        }
        else{
            m[pre]=i;
        }


        }




return longest;



}
int main(){

int n;
cin>>n;
int *arr=new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int k;
cin>>k;
int len=longestsubsumk(arr,n,k);
cout<<len<<endl;



return 0;
}


