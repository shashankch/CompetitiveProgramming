
#include<iostream>
using namespace std;



bool subset(int *arr,int n,int i,int sum,bool included){


        if(i>=n){

            if(sum==0 && included){

            return true;

            }
            else{
                return false;
            }

        }


    sum+=arr[i];
      cout<<"before the include call: "<<sum<<endl;
      bool in= subset(arr,n,i+1,sum,true);

        cout<<"after the include call: "<<sum<<endl;
        bool ex=  subset(arr,n,i+1,sum,included);





       return in||ex;

}










int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;
        int arr[n];

    for(int i=0;i<n;i++){

        cin>>arr[i];
    }

    if(subset(arr,n,0,0,false)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


    }


return 0;
}
