
#include<iostream>
using namespace std;



int power(int a,int b){

    if(b==0)
        return 1;

    if(b==1){
        return a;
    }

    int temp=power(a,b/2);

    if(b&1){
        return a*temp*temp;
    }
    return temp*temp;
}









int main(){


int a,b;
cin>>a>>b;
cout<<power(a,b);
return 0;
}
