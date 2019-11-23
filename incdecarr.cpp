


#include<iostream>

using namespace std;


void increasing(int n){


if(n==0) return ;

increasing(n-1);
cout<<n<<" ";





}
void decreasing(int n){


    if(n==0) return ;
cout<<n<<" ";
decreasing(n-1);








}






int main(){

int n;
cin>>n;


cout<<"increasing no:";
increasing(n);
cout<<endl;
cout<<"decreasing no:";
decreasing(n);






return 0;
}

