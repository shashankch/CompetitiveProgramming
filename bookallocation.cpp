
#include<iostream>
using namespace std;

bool isvalid(int arr[],int n,int k,int mid){

        int curr=0;
        int student=1;
    for(int i=0;i<n;i++){

        if(curr+arr[i]>mid){

            curr=arr[i];
            student++;
            if(student>k){
                return false;
            }
        }
        else{
            curr+=arr[i];
        }


    }


return true;

}

int bookalloc(int arr[],int n,int k){

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

            ans=mid;
            e=mid-1;

        }
        else{
            s=mid+1;
        }



    }


return ans;

}

int main(){

int t,n,k;
cin>>t;
int arr[10005];
while(t--){

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ///minimize the max book pages
    cout<<bookalloc(arr,n,k)<<endl;

}






return 0;
}
