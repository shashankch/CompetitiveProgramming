

#include<iostream>
using namespace std;


void image(int arr[][10],int n){


    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            swap(arr[i][j],arr[j][i]);
            }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(arr[j][i],arr[n-1-j][i]);
        }
    }

    for(int i=0;i<n;i++)
{

    for(int j=0;j<n;j++){
       cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}








}
int main(){

int n;
cin>>n;
int arr[10][10];

for(int i=0;i<n;i++)
{

    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}

image(arr,n);





return 0;
}
