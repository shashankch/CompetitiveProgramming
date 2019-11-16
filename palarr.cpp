
#include<iostream>
using namespace std;
bool palrec(int arr[],int l,int r){

if(l>r){
    return true;
}


if(arr[l]==arr[r]){
return   palrec(arr,++l,--r);
}
else{
    return false;
}


}

bool util(int arr[],int n){


int l=0;
int r=n-1;
return palrec(arr,l,r);

}





bool pal(int arr[],int n){

int l=0;
int r=n-1;
while(l<=r){
    if(arr[l]!=arr[r]){
        return false;
    }
    l++;
    r--;
}
return true;

}


int main(){

int n;
int arr[100];
cin>>n;
for(int i=0;i<n;i++){
    cin>>arr[i];
}

if(util(arr,n)){
    cout<<"true";
}
else{
    cout<<"false";
}



return 0;
}
