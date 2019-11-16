


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



    bool stringsort(string a,string b){
        int i=0;
        while(a[i]==b[i]) i++;

        if(a[i]=='\0') return false;
        else if(b[i]=='\0') return true;
        else return a<b;
    }

int  main(){
int n;
string arr[100];

cin>>n;
//cin.ignore();
for(int i=0;i<n;i++){

    cin>>arr[i];
}


sort(arr,arr+n,stringsort);
for(int i=0;i<n;i++){

    cout<<arr[i]<<endl;
}



return 0;
}
