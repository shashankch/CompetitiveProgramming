
#include<iostream>
#include<algorithm>
using namespace std;



void rain_trap(int arr[10000],int n);
{

  int left[]=new int[n];
  int right[]=new int [n];

  int left[0]=arr[0];
  int right[n-1]=arr[n-1];

  for(int i=1;i<n;i++){

    left[i]=max(arr[i],left[i-1]);
  }

  for(int i=n-2;i>=0;i--){
    right[i]=max(arr[i],left[i+1]);
  }
  int water =0;
  for(int i=0;i<n;i++){

     water+=min(left[i],right[i])-arr[i];

  }

    cout<<water;

}












void print_triple_sum(int arr[10000],int n,int target){


for(int i=0;i<n;i++){

    int l=i+1;
    int r=n-1;

    while(l<r){

        if(arr[i]+arr[l]+arr[r]==target){
            cout<<arr[i]<<", "<<arr[l]<<" and "<<arr[r]<<endl;
           l++;
           r--;
        }
        else if(arr[i]+arr[l]+arr[r]>target){
            r--;
        }
        else if(arr[i]+arr[l]+arr[r]<target){
            l++;
        }



    }




}



}






int main(){


int n,target,arr[10000];

cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cin>>target;
sort(arr,arr+n);
print_triple_sum(arr,n,target);


return 0;
}

