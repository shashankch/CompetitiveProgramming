

#include<iostream>
using namespace std;



int binarysearch(int n,int k,int arr[]){

int s=0;
int e=n-1;
int mid;

while(s<=e){

    mid=(s+e)/2;
    if(arr[mid]==k){
        return mid;
    }
    else if(arr[mid]<k){
        s=mid+1;
    }
    else{
        e=mid-1;
    }
}
return -1;
}








int main(){


int n,k,arr[100];
cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cin>>k;
cout<<binarysearch(n,k,arr);




return 0;
}
