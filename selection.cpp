#include<iostream>
#define ll long long int
using namespace std;



    void selection(ll n,ll arr[]){

        int minv;

        for(int i=0;i<n-1;i++){
                minv=i;
            for(int j=i+1;j<n;j++){

                if(arr[j]<arr[minv]){
                       minv=j;
                        }
            }
            swap(arr[i],arr[minv]);

}
    }

int  main(){
ll n;
ll arr[100];

cin>>n;
for(int i=0;i<n;i++){

    cin>>arr[i];
}

selection(n,arr);
for(int i=0;i<n;i++){

    cout<<arr[i]<<endl;
}
cout<<INT_MAX;


return 0;
}
