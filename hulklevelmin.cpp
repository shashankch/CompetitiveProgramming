
#include<iostream>
using namespace std;



int minjump(int a){

    int c=0;
    while(a>0){
        c++;
        a=a&(a-1);
    }





return c;
}
int main(){

int t;
cin>>t;
while(t--){

    int a;
    cin>>a;
    cout<<minjump(a)<<endl;

}




return 0;
}
