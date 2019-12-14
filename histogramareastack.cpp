


/// brute force method : o(n2)
/// divide and conquer method : o(nlogn)
/// below method is stack based: o(n)
#include<iostream>
#include<stack>
# define ll long long int

using namespace std;

int main(){

stack<ll>s;
ll n,area=0;
cin>>n;
ll *arr=new ll[n];
for(ll i=0;i<n;i++){

    cin>>arr[i];
}
ll i;

/// here first check if element is greater than stack top then insert otherwise take top of stack as current element..........>>
/// as min height and i th index (at which min ht element occurred)--right part and left part is next small top of stack and find the area..
for( i=0;i<n;i++){


    while(!s.empty()){
    if(arr[i]>=arr[s.top()]){
        break;

    }
    int curr=s.top();
    s.pop();

    if(!s.empty()){

        area=max(area,arr[curr]*(i-s.top()-1));
    }
    else{
        area=max(area,arr[curr]*i);
    }


    }
    s.push(i);



}

while(!s.empty()){
     int curr=s.top();
       s.pop();
     if(!s.empty()){



        area=max(area,arr[curr]*(n-s.top()-1));
    }
    else{
        area=max(area,arr[curr]*n);
    }



}

cout<<area;


return 0;
}
