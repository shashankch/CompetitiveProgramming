
#include<iostream>
#include<algorithm>
using namespace std;


int multiplytwo(int a,int b){



        if(b==0)
            return 0;
        if(b==1) return a;

        return a+multiplytwo(a,b-1);
        /// return a<<1+multiplytwo(a,b-2);
}






int main(){

int a,b;
cin>>a>>b;
int res=multiplytwo(a,abs(b));
int ans=(b<0)? -res:res;
cout<<ans;

return 0;
}

