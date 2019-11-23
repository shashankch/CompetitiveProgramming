
#include<iostream>
using namespace std;


int linearecur(int arr[],int i,int n,int k){

        if(i==n) return -1;

        if(arr[i]==k) return i;


        return linearecur(arr,i+1,n,k);






}






int main(){

int arr[]={1,3,5,4,7,4};

int n=sizeof(arr)/sizeof(int);

cout<<linearecur(arr,0,n,17);



return 0;
}

