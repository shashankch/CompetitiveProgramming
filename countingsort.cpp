

#include<iostream>
using namespace std;



    void counting(int n,int arr[]){

    int p=0;
    int cnt[1000001]={0};
          int output[n];
        for(int i=0;i<n;i++){
        cnt[arr[i]]++;}

        for(int i=0;i<=1000001;i++){

            while(cnt[i]--){
                output[p++]=i;
            }


        }

        for(int i=0;i<n;i++){
            cout<<output[i]<<" ";
        }

    }

int  main(){
int n,arr[1000001];

cin>>n;
for(int i=0;i<n;i++){

    cin>>arr[i];
}

counting(n,arr);



return 0;
}

