
#include<iostream>
using namespace std;



    void bubble(int n,int arr[]){


        for(int i=0;i<n-1;i++){
          //optimization for sorted array // int flag=0;
            for(int j=0;j<n-i-1;j++){

                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    flag=1;
                }
            }
                            // if(flag==0){
                            //   break;
                            // }
    }




    }

int  main(){
int n,arr[100];

cin>>n;
for(int i=0;i<n;i++){

    cin>>arr[i];
}

bubble(n,arr);
for(int i=0;i<n;i++){

    cout<<arr[i]<<" ";
}



return 0;
}
