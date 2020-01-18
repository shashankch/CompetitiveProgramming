

///spoj BAISED - Biased Standings
#include<iostream>

using namespace std;



int main(){

int t;
cin>>t;
while(t--){
int n;
cin>>n;
int arr[n+1]={0};
for(int i=1;i<=n;i++){

    string team;
    int rk;
    cin>>team;
    cin>>rk;
    arr[rk]++;
}

int pos=1;
int sum=0;
for(int i=1;i<=n;i++){

    while(arr[i]--){

        sum+=abs(pos-i);
        pos++;
    }

}

cout<<sum<<endl;
}





return 0;
}
