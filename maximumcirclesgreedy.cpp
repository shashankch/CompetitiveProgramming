
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool compare(pair<int,int>a,pair<int,int>b){

     if(a.second==b.second){
    return a.first<b.first;
   }
   return a.second<b.second;

}


/// total no.of circles intersecting=total no.of circles-circles not intersecting..

int main(){

int n;
cin>>n;
int c,r;
vector<pair<int,int> >v;
for(int i=0;i<n;i++){

    cin>>c>>r;
    v.push_back(make_pair(c-r,r+c));


}

sort(v.begin(),v.end(),compare);

 int fin=v[0].second;
    int res=0;
    for(int i=1;i<v.size();i++){

           if(v[i].first>=fin){

            fin=v[i].second;
            res++;
           }



    }

    cout<<"Total no.of circles to remove(intersection): "<<n-res-1<<endl;









return 0;
}
