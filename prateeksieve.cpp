#include <iostream>
using namespace std;




void primeSieve(int *p,int n){

    p[0] = p[1] = 0;
    p[2] = 1;


    for(int i=3;i<=n;i+=2){
        p[i] = 1;
    }


    for(int i=3;i<=n;i+=2){

        if(p[i]){

            for(int j=i*i;j<=n;j+=2*i){
                p[j] = 0;
            }
        }

    }
    return;
}




int main() {
    int N = 10000;

    int p[N] = {0};
    primeSieve(p,10000);

    int t;
    cin>>t;
    while(t--){
    int n;
	int c=0;
    cin>>n;
    for(int i=0;i<=N;i++){
        if(p[i]){
           c++;
           if(c==n){
            cout<<i<<endl;
			break;
           }
        }
    }

}
return 0;
}
