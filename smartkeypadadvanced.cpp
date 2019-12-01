#include<iostream>
#include<string>
#include<vector>

using namespace std;

string table[] = { "", "", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };
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

    for(int j=0;j<11;j++){

        if(searchIn[j].find(l[i])!=string::npos){
            cout<<searchIn[j]<<endl;
        }
    }
}

return 0;
}


/*
static String table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    private static final String[] searchIn = { "prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh",
            "divyam", "vidhi", "sparsh", "akku" };

    public static void keypad1(String ques, String ans) {

        if (ques.length() == 0) {
            for (String ss : searchIn) {
                if (ss.contains(ans)) {
                    System.out.println(ss);
                }
            }

            return;
        }

        char ch = ques.charAt(0);
        String ros = ques.substring(1);
        String code = table[ch - '0'];

        for (int i = 0; i < code.length(); i++)
            keypad1(ros, ans + code.charAt(i));

    }


*/
