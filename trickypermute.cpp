
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


vector<string>ans;
bool ifpresent(string str,int i,int j){

for(int k=i;k<j;k++){
            if(str[j]==str[k]){
               return false;
            }
        }

        return true;
}




void trickypermute(string str,int len,int i){


    if(i==str.length()){

        ans.push_back(str);
        //cout<<str<<endl;
        return ;
    }
    int flag=0;
    for(int j=i;j<str.length();j++){


        if(ifpresent(str,i,j)){
            swap(str[i],str[j]);
            trickypermute(str,len,i+1);
            }
        }
}
int main(){


string str;
cin>>str;
int len=str.length();
trickypermute(str,len,0);
sort(ans.begin(),ans.end());
for(auto x:ans){
    cout<<x<<endl;
}


return 0;
}

/*

public class Main {
    public static void main(String args[]) {

        Scanner scn = new Scanner(System.in);

        String str = scn.next();

        char[] charray = str.toCharArray();
        Arrays.sort(charray);

       permutationNoDuplicates(new String(charray), "");
    }

   public static void permutationNoDuplicates(String ques, String ans) {

        if (ques.length() == 0) {
            System.out.println(ans);
            return;
        }

        for (int i = 0; i < ques.length(); i++) {

            char ch = ques.charAt(i);
            String roq = ques.substring(0, i) + ques.substring(i + 1);

            boolean flag = true;

            for (int j = i + 1; j < ques.length(); j++) {
                if (ques.charAt(j) == ch) {
                    flag = false;
                }
            }

            if (flag)
                permutationNoDuplicates(roq, ans + ch);
        }

    }
}
*/
