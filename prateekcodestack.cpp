
#include<iostream>
#include<stack>
using namespace std;





int main(){

stack<int>s;
int q,t,cost;
cin>>q;
while(q--){

    cin>>t;
    if(t==2){
        cin>>cost;
        s.push(cost);
    }
    else if(t==1){
         if(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
         }
         else{
            cout<<"No Code"<<endl;
         }
    }


}



return 0;
}
