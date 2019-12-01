#include<iostream>
#include<string>
#include<vector>

using namespace std;

string table[] = { "", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wx","yz" };

vector<string> l;

void smartkeycode(char *code,char *out,int i,int j)
{
    if(code[i]=='\0'){
        out[j]='\0';
        l.push_back(out);

    return;
    }

    int digit=code[i]-'0';

    for(int p=0;p<table[digit].length();p++){

        out[j]=table[digit][p];
        smartkeycode(code,out,i+1,j+1);

        }
}










int main(){

char code[100],out[100];
cin>>code;

smartkeycode(code,out,0,0);


for(int i=0;i<l.size();i++){


            cout<<l[i]<<" ";
        }
        cout<<endl;
        cout<<l.size();

return 0;
}

