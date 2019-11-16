
#include<iostream>

using namespace std;


int uniqueone(int arr[],int n){

    int ans=0;
    for(int i=0;i<n;i++){

        ans^=arr[i];

    }








    return ans;

}
int main(){

int n;
int arr[1003];
cin>>n;

for(int i=0;i<n;i++){
    cin>>arr[i];
}
cout<<uniqueone(arr,n);

return 0;
}
