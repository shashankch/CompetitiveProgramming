
#include<iostream>

using namespace std;
int psum=0;
int nsum=0;
void optimalgame(int *arr,int start,int end,int moves,int n)
{

    if(moves==n){
        cout<<psum;
        return;
    }



    if(arr[start]>arr[end]){
    if(moves%2==0)
    {
            psum+=arr[start];



    }
    else{
        nsum+=arr[start];
    }

    optimalgame(arr,start+1,end,moves+1,n);

    }
    else{

        if(moves%2==0){


            psum+=arr[end];
        }
        else {
            nsum+=arr[end];
        }



 optimalgame(arr,start,end-1,moves+1,n);
    }

return ;

}




int main(){

int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){

    cin>>arr[i];

}

optimalgame(arr,0,n-1,0,n);



return 0;
}
