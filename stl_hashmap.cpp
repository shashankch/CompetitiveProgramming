
#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

class fruit{
public:
    string name;
    int price;
    string city;


    fruit(){


    }
    fruit(string n,int p,string c){

        name=n;
        price=p;
        city=c;


    }

};



int main(){
/// not specific order they are unordered.. whereas map is ordered follows bst..
unordered_map<string,int> mymap;
mymap["Mango"]=100;
mymap.insert(make_pair("Apple",120));

pair<string,int> p("litchi",130);
mymap.insert(p);

for(auto node:mymap){
    cout<<node.first<<","<<node.second<<endl;
}
for(int i=0;i<mymap.bucket_count();i++){
    cout<<"Bucket"<<i<<"->";  /// iterate over every linked list ith
    for(auto it=mymap.begin(i);it!=mymap.end(i);it++){
            /// it is a pointer to a pair
        cout<<it->first<<","<<it->second;
    }
    cout<<endl;
}

unordered_map<string,fruit> myfruit;
fruit f("Mango",100,"Delhi");
myfruit[f.name]=f;
fruit fs=myfruit["Mango"];
cout<<fs.city<<endl;

/// count function

cout<<"Mango"<<myfruit.count("Mango")<<endl;

cout<<"enter fruit to search";
string fruits;
cin>>fruits;
myfruit.erase("Mango");
if(myfruit.count(fruits)!=0){
    cout<<myfruit[fruits].price<<endl;
}
else{
    cout<<"fruit does'nt exists";
}







return 0;
}
