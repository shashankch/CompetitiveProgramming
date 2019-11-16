#include<iostream>
using namespace std;

bool isvalid(int arr[],int n,int k,int mid){

        int curr=0;
        int painter=1;
    for(int i=0;i<n;i++){

        if(curr+arr[i]>mid){

            curr=arr[i];
            painter++;
            if(painter>k){
                return false;
            }
        }
        else{
            curr+=arr[i];
        }


    }


return true;

}

int painter(int arr[],int n,int k,int t){

    int s=0,e,total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
        s=max(s,arr[i]);
    }
    e=total;
    int ans=0;
    while(s<=e){
        int mid=(s+e)/2;

        if(isvalid(arr,n,k,mid)){

            ans=mid*t;
            e=mid-1;

        }
        else{
            s=mid+1;
        }



    }


return ans;

}

int main(){

int n,k,t;
cin>>n>>k>>t;
int arr[10005];

for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<painter(arr,n,k,t)%10000003;
return 0;
}
