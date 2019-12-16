#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;





int hungrymoves(vector<int>faqua,int ifish){

    int moves=0;
    for(int i=0;i<faqua.size();i++){

        if(ifish>faqua[i]){
            faqua[i]=ifish+faqua[i];
            ifish=ifish+faqua[i];

        }
    }
    if(faqua.size()==2){
        moves+=1;
    }
    else{


    }




}

int main(){


string str,temp;
cin>>str;
vector<string>tokens;
vector<string>aqua;
vector<int>faqua;
stringstream check(str);
while(getline(check,temp,'#')){
    tokens.push_back(temp);
}
int ifish=stoi(tokens[0]);
cout<<ifish<<endl;
vector<string>fishnum;
string fish=tokens[1];
stringstream check2(fish);
while(getline(check2,temp,',')){
    fishnum.push_back(temp);
}
vector<int>aquarium;
for(int i=0;i<fishnum.size();i++){

     faqua.push_back(stoi(fishnum[i]));
      aquarium.push_back(stoi(fishnum[i]));
    cout<<faqua[i]<<endl;
}
aquarium.push_back()

cout<<hungryfish(faqua,ifish);

return 0;
}
