
#include<iostream>
#include<cstring>
using namespace std;


bool compare(string a,string b){

    if(a>b){
        return true;
    }

    return false;




}



void dictionarylarge(char *in,int i,char *cpy){

 ///base case : when input is so small // when reach the end of the char array.
    if(in[i]=='\0'){

        if(compare(in,cpy)){
            cout<<in<<endl;
        }
        return;
    }
    /// recursive case: swap the current char with next char and call for remaining array
    /// i : current char // j-i to.. for traversing.
    for(int j=i;in[j]!='\0';j++){

        swap(in[i],in[j]);/// going down the tree.
        dictionarylarge(in,i+1,cpy);  /// call for the remaining char array
        swap(in[i],in[j]); /// backtracking : restoring the original array going up the tree

    }







}
int main(){

char in[100],cpy[100];

cin>>in;
strcpy(cpy,in);
dictionarylarge(in,0,cpy);


return 0;
}
