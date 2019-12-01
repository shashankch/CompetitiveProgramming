
/// still trying pending .................different approach..
#include<iostream>
#include<cstring>
using namespace std;




void dictionarylarge(string in,int i,string cpy){


    if(i==cpy.length()){

        if(in.compare(cpy)!=0){
            cout<<in<<endl;
        }
        return;
    }

    for(int j=i+1;j<in.length();j++){

        if(in[i]<in[j]){
        swap(in[i],in[j]);
        }
        dictionarylarge(in,i+1,cpy);
        swap(in[i],in[j]);

    }







}
int main(){

string in,cpy;

cin>>in;
cpy=in;
dictionarylarge(in,0,cpy);


return 0;
}

