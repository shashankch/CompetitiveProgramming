
#include<iostream>
using namespace std;

int setbit(int n){

    int c=0;
    while(n>0){
        c++;
        n=n&(n-1);


    }






return c;
}
int main(){

int q;
cin>>q;

while(q--){

    int a,b,ans=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
    ans+=setbit(i);
    }

    cout<<ans<<endl;
}


return 0;
}
