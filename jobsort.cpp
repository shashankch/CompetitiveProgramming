


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



    bool compare(pair<string,int>p1,pair<string,int>p2){


        if(p1.second==p2.second){
            return p1.first<p2.first;
        }
        return p1.second>p2.second;
}

int  main(){
int n,k;
pair<string,int> job[100005];
cin>>k>>n;

string name;
int salary;
for(int i=0;i<n;i++){

    cin>>name>>salary;
    job[i].first=name;
    job[i].second=salary;
}


sort(job,job+n,compare);
for(int i=0;i<n;i++){
    if(job[i].second>=k){
    cout<<job[i].first<<" "<<job[i].second<<endl;
}}



return 0;
}
