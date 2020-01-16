#include<iostream>
using namespace std;

string minwindownsubstring(string str, string pat){

    int len1=str.length();
    int len2=pat.length();

    if(len1<len2){

        return "No string";

    }
    int has_pat[256]={0};
    int has_str[256]={0};

    for(int i=0;i<len2;i++){

        has_pat[pat[i]]++;
    }
    int min_length=INT_MAX,count=0,start=0,start_index=-1;

    for(int j=0;j<len1;j++){

        has_str[str[j]]++;

        /// expansion of window from 0th index.. max window containing whole pat..
        if(has_pat[str[j]]>=has_str[str[j]] and has_pat[str[j]]!=0){
            count++;
        }
        /// now shrinking part.. once length becomes equal to pattern length...
        if(count==len2){
            while(has_pat[str[start]]==0 or has_pat[str[start]]<has_str[str[start]])
                {
                    if(has_pat[str[start]]<has_str[str[start]]){
                    has_str[str[start]]-=1;
                    }
                    start+=1;


                }

                int len_wind=j-start+1;
                if(min_length>len_wind){
                    min_length=len_wind;
                    start_index=start;
                }




        }



    }
    if(start_index==-1){
         return "No string";
    }




    return str.substr(start_index,min_length);


}













int main(){

string str,pat;
getline(cin,str);
getline(cin,pat);
cout<<minwindownsubstring(str,pat);


return 0;
}
