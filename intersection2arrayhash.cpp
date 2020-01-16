#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;


int main(){

int n;
cin>>n;
int *a=new int[n];
int *b=new int[n];
for(int i=0;i<n;i++){

    cin>>a[i];
}
for(int i=0;i<n;i++){

    cin>>b[i];
}
unordered_map<int,int>mp;
for(int i=0;i<n;i++){
    if(mp.find(a[i])!=mp.end()){

        mp[a[i]]+=1;

    }
    else{
    mp.insert(make_pair(a[i],1));
    }
}
vector<int>v;
for(int i=0;i<n;i++){

    if(mp.find(b[i])!=mp.end()){
        v.push_back(b[i]);
        mp[b[i]]-=1;


    }
    if(mp[b[i]]<=0){
        mp.erase(b[i]);
    }


}
sort(v.begin(),v.end());
cout<<"[";
int i;
for( i=0;i<v.size()-1;i++){
    cout<<v[i]<<", ";
}
cout<<v[i]<<"]";



return 0;
}







/*
int main(){

unordered_map<int,int>mymap;

int n;
cin>>n;
int a[n],b[n];
for(int i=0;i<n;i++){
cin>>a[i];
}
for(int i=0;i<n;i++){
cin>>b[i];
}

for(int i=0;i<n;i++){

    mymap[a[i]]=a[i];

}
vector<int>v;
//cout<<"Intersection values:";

for(int i=0;i<n;i++){

    if(mymap.find(b[i])!=mymap.end()){
        v.push_back(b[i]);
    }

}

sort(v.begin(),v.end());
cout<<"[";
int i;
for( i=0;i<v.size()-1;i++){

	cout<<v[i]<<", ";
}
cout<<v[i]<<"]";



return 0;

}
*/
