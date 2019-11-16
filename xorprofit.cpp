
#include<iostream>
using namespace std;



int maxor(int a,int b){

        int ans=0;
    for(int i=a;i<b;i++){

        ans=max(ans,i^(i+1));

    }


return ans;

}







int main(){

int a,b;
cin>>a>>b;
cout<<maxor(a,b);


return 0;
}
