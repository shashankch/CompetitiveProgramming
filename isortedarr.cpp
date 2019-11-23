

#include<iostream>
///#include<algorithm>
using namespace std;

bool isorted(int arr[],int n){


    if(n==1) return true;

    if(arr[0]<=arr[1] && isorted(arr+1,n-1)){
        return true;
    }

return false;

}







int main(){


int arr[]={3,4,5,2,2,3};

int n=sizeof(arr)/sizeof(int);
///sort(arr,arr+n);
cout<<isorted(arr,n);


return 0;
}
