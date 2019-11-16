
#include<iostream>
using namespace std;


void sum_arr(int a1[],int n1,int a2[],int n2){


    int fr[n1+1];
    int res[n1];
    int s=n1-1;
    int k=n1-1;
    int carry=0,sum=0,ans=0;
    int i=n2-1;
    int j=n1-1;
    int pos=n1-1;
while(i>=0){

    sum=a2[i--]+a1[s--]+carry;

    res[k--]=(sum%10);

    carry=sum/10;
}
while(s>=0){

    sum=a1[s--]+carry;
    res[k--]=(sum%10);
    carry=sum/10;
}
if(carry){
     ans = 10;
     j=n1;
     pos=n1;
}

    for (int i = 0; i <= n1 - 1; i++) {
        ans += res[i];
        ans *= 10;

    }
    int val=ans/10;
    while(val!=0){
       fr[j--]=val%10;
       val/=10;

    }

for(int i=0;i<=pos;i++){
    cout<<fr[i]<<", ";
}
cout<<"END";


}
int main(){

int n1,n2,a1[1005],a2[1005];

cin>>n1;
for(int i=0;i<n1;i++){
    cin>>a1[i];
}

cin>>n2;
for(int i=0;i<n2;i++){
    cin>>a2[i];
}

if(n1>n2){

sum_arr(a1,n1,a2,n2);
}
else {
sum_arr(a2,n2,a1,n1);

}
return 0;
}
