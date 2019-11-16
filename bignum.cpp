
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



int comparator(string s1,string s2){

string xy=s1.append(s2);
string yx=s2.append(s1);
return xy.compare(yx)>0?1:0;
}

void big(string arr[],int n){



sort(arr,arr+n,comparator);


 for (int i=0;i<n;i++){
        cout << arr[i];}

        cout<<endl;

}

int main(){

int t,n;

string arr[100];

cin>>t>>n;
while(t--){
for(int i=0;i<n;i++){
    cin>>arr[i];
}
big(arr,n);

}
return 0;
}
