
#include<iostream>

using namespace std;


void pivotelement(int arr[],int n)
{
    int s=0;
    int e=n-1;
    while(s<=e){

        int mid=(s+e)/2;

        if(arr[mid]>arr[mid+1]){
            cout<<mid;
            break;
        }
        else if(arr[mid]<arr[mid-1]){
            cout<<mid-1;
            break;
        }
        else if(arr[s]>=arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }


}



}
int main(){


int n,arr[1000];
cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
pivotelement(arr,n);




return 0;
}
