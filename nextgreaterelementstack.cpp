
#include<iostream>
#include<stack>
using namespace std;



void printnextgrt(int *arr,int n){

stack<int> s;
s.push(arr[0]);
for(int i=1;i<n;i++){


    while(!s.empty() && arr[i]>s.top()){

        cout<<arr[i]<<" ";
        s.pop();
    }
    s.push(arr[i]);
}
    while(!s.empty()){
        cout<<-1<<" ";
        s.pop();
    }




}

int main(){

int n,arr[100];
cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
printnextgrt(arr,n);


return 0;
}


