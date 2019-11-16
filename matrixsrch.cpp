
#include<iostream>
using namespace std;

int  matrix_search(int arr[][10],int r,int c,int target){

int i=0,j=c-1;
    while(i<r && j>=0){

        if(arr[i][j]==target){
            return 1;
        }
        else if(arr[i][j]>target){
           j--;
        }
        else {
            i++;
        }




    }
return 0;
}


int main(){

int r,c,arr[10][10];
cin>>r>>c;

for(int i=0;i<r;i++){

    for(int j=0;j<c;j++){
        cin>>arr[i][j];
    }
}
int target;
cin>>target;
cout<<matrix_search(arr,r,c,target);



return 0;
}
