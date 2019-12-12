
#include<iostream>
#include<cstring>
using namespace std;





int main(){

char a[]="abcdefac";  ///6 length
int l=strlen(a);
int mx=1;
int clen=1;
int visited[256];
for(int i=0;i<256;i++){
    visited[i]=-1;
}
visited[a[0]]=0;
for(int i=1;i<l;i++){

    int lastoc=visited[a[i]];

    ///expansion : in case of no last occurence or if last occurence is outside the window..
    if(lastoc==-1 || lastoc<(i-l)){
        clen+=1;

    }

    /// expansion and contraction
    else{
          if(clen>mx){
            mx=clen;
        }

            clen=i-lastoc;

    }

    /// visited that character..
    visited[a[i]]=i;

}

if(clen>mx){
                mx=clen;
            }


cout<<mx<<endl;




return 0;
}
