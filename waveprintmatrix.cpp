

#include<iostream>
using namespace std;

void waveprint(int arr[][10],int r,int c){


    for(int j=0;j<c;j++){

            if(j&1){
                for(int i=r-1;i>=0;i--){
                    cout<<arr[i][j]<<" ";
                }

            }
            else{

                for(int i=0;i<r;i++){
                    cout<<arr[i][j]<<" ";

                }
            }
        }
    }




}




int main(){

int arr[10][10];

waveprint(arr,10,10);

return 0;
}
