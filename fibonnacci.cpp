


#include<iostream>
using namespace std;



    int fibo(int n){


    if(n==0 || n==1) return n;


    int fib1=fibo(n-1);
    int fib2=fibo(n-2);

    return fib1+fib2;

}










int main(){

int n;

cin>>n;

cout<<fibo(n);


return 0;
}
