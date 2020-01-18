
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(pair<int,int>a,pair<int,int>b){


    double r1=a.first/a.second;
    double r2=b.first/b.second;

    return r1>r2;

}




int main(){

int kw;
cin>>kw;
vector<pair<int,int> >v;
int n;
cin>>n;
for(int i=0;i<n;i++){
    int val,w;
    cin>>val>>w;
    v.push_back(make_pair(val,w));
}
sort(v.begin(),v.end(),compare);
int currwt=0;
double finalval=0.0;
for(int i=0;i<v.size();i++){

    if(currwt+v[i].second<=kw){

        currwt+=v[i].second;
        finalval+=v[i].first;

    }
    else{

        int remwt=kw-currwt;
        finalval+=remwt*(v[i].first/v[i].second);
    }


}


cout<<"Maximum final value:"<<finalval<<endl;



return 0;

}
