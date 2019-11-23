

#include<iostream>
#include<algorithm>
using namespace std;


int binaryrecur(int arr[],int s,int e,int k){


        if(s>e){
            return -1;
        }

         int mid=(s+e)/2;
        if(arr[mid]==k){
            return mid;
        }

      if(arr[mid]<k){
        return binaryrecur(arr,mid+1,e,k);

      }
      else{
        return binaryrecur(arr,s,mid-1,k);
      }


}






int main(){

int arr[]={1,3,5,4,7,4};

int n=sizeof(arr)/sizeof(int);

sort(arr,arr+n);

cout<<binaryrecur(arr,0,n-1,7);



return 0;
}

