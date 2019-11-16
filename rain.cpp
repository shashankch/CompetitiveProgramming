#include<iostream>
#include<algorithm>
using namespace std;



int rain_trap(int arr[10000],int n)
{

  int *left=new int[n];
  int *right=new int[n];

left[0]=arr[0];
  right[n-1]=arr[n-1];

  for(int i=1;i<n;i++){

    left[i]=max(arr[i],left[i-1]);
  }

  for(int i=n-2;i>=0;i--){
    right[i]=max(arr[i],right[i+1]);
  }
  int water =0;
  for(int i=0;i<n;i++){

     water+=min(left[i],right[i])-arr[i];

  }

  return water;

}

int main(){


int n,arr[10000];

cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}


cout<<rain_trap(arr,n);


return 0;
}
