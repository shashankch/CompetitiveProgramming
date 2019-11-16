
#include<iostream>
using namespace std;


int cb_num(int a){

    if(a<=1)
        return 0;
    if(a<=3)
        return 1;
    if(a%3==0||a%2==0)
        return 0;
    for(int i=5;i*i<a;i=i+6)
        if(a%(i)==0||a%(i+2)==0)
            return 0;
    return 1;


}
bool visited(int v[],int i,int j){


for(int k=i;k<=j;k++){
    if(v[k]==1){
        return true;
    }
}
return false;


}

int main()
{

    int n;
    string s;

    cin>>n;
    cin>>s;
    int cnt=0;
    int v[n]={0};
    for(int i=0;i<n;i++){

        for(int j=0;j<n-i;j++){

            int p=j;
            int q=j+i;
            int temp=0;
            while(p<=q){
                    temp=temp*10+(s[p]-'0');
                    p++;

            }

        if(cb_num(temp)){

           if(!visited(v,j,j+i)){
            cnt++;
             for(int k=j;k<=j+i;k++)
                            v[k]=1;
           }



        }

    }
    }


cout<<cnt;

    return 0;
}
