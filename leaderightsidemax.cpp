#include<bits/stdc++.h>

using namespace std;
vector<int>ans;
void findmaxr(int *arr,int n){

        int mx=INT_MIN;
        for(int i=n-1;i>=0;i--){

            if(arr[i]>mx){
                mx=arr[i];
                ans.push_back(arr[i]);
            }
        }
    
    }

int main(){

    int arr[]={4,6,1,0,2,9};
    findmaxr(arr,6);
    for(int n:ans){
        cout<<n<<" ";
    }



    return 0;
}