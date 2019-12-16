




#include<iostream>
#include<queue>
using namespace std;

int main(){


queue<int> q;
int n,data,time=0;
cin>>n;

int arr2[101];
for(int i=0;i<n;i++){
    cin>>data;
    q.push(data);
}
for(int i=0;i<n;i++){
    cin>>arr2[i];
}

int cnt=0;
while(!q.empty()){

    if(arr2[cnt]==q.front()){
             q.pop();
            time+=1;
            cnt+=1;
        }
    else{
        int top=q.front();
        q.pop();
        q.push(top);
        time+=1;
    }
}

cout<<time;


return 0;
}
