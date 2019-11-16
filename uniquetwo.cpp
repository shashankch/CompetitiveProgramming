
#include<iostream>

using namespace std;


void findunique(int arr[],int n){

    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
int pos=0;
while(ans>0){

    if((ans&1)==0){
        pos++;
    }
    ans=ans>>1;

}
int mask=1<<pos;
int a=0,b=0;
for(int i=0;i<n;i++){

    if(arr[i]&mask!=0){
        a=a^arr[i];
    }
    else{
        b=b^arr[i];
    }
}

cout<<a<<" "<<b;


}

int main(){


int n,arr[1003];
cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}
findunique(arr,n);

return 0;
}
