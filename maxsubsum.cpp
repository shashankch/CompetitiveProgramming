

#include<iostream>
#include<algorithm>
using namespace std;




int max_sum(int *arr,int n){


int cs=0,ms=0;

for(int i=0;i<n;i++){

    cs+=arr[i];
    if(cs<0){
        cs=0;
    }
    ms=max(ms,cs);
}




return ms;

}





int main(){



int t,n,arr[100000000];
cin>>t;
while(t--){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max_sum(arr,n)<<endl;


}






return 0;

}
