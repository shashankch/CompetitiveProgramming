#include<iostream>
#include<algorithm>
using namespace std;

int main(){


int arr[]={20,30,40,40,40,50,100,1100};
int n=sizeof(arr)/sizeof(int);
//find function
 int key=40;
 auto it=find(arr,arr+n,key);
cout<<it<<endl;
// returns the address of the found element.

// to get the index
cout<<it-arr<<endl;

if (it-arr==n){
    cout<<"element not present";
}
else{
    int index=it-arr;
    cout<<index<<endl;
}

bool present =binary_search(arr,arr+n,key);

if(present){
    cout<<"hurray! found it..";
}
else{
    cout<<"not found";
}

// get the index of the element..
//lower_bound(s,e,key) and upper_bound(s,e,key)
// lower bound returns the index of the element greater than equal to key..
auto lb=lower_bound(arr,arr+n,40);
cout<<endl<<"lower bound of 40 is"<<lb-arr<<endl;

//upper bound returns the first striclty greater than key..

auto ub=upper_bound(arr,arr+n,40);
cout<<endl<<"Upper bound of 40 is"<<ub-arr<<endl;

// if(it-arr==n){
//     cout<<"element not present"<<endl;
// }



// no. of elements present b/w and used to find freq of  key element.
cout<<"occ freq of key is "<<ub-lb<<endl;
// check freq to determine element is present or not because upper bound==lower bound in such cases.

// sort an array using sort() function
int n=10;
int ar[10];
sort(ar,ar+n);



    return 0;
}