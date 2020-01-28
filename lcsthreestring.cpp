



#include<iostream>
#include<cstring>
using namespace std;
 int dp[201][201][201];
int lcs3d(char x[],char y[],char z[]){

    int m=strlen(x);
    int n=strlen(y);
    int p=strlen(z);



    ///base case
     for(int i=0;i<=m;i++){
        dp[i][0][0]=0;
    }
     for(int i=0;i<=n;i++){
        dp[0][i][0]=0;
    }
     for(int i=0;i<=p;i++){
        dp[0][0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
                for(int k=1;k<=p;k++){

            int q=0;
            if(x[i-1]==y[j-1] && y[j-1]==z[k-1]){
                q=1+dp[i-1][j-1][k-1];
            }
            else{
                q=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
            }
            dp[i][j][k]=q;
        }
    }
    }
    return dp[m][n][p];

}
int main(){

char a[200],b[200],c[200];
cin>>a>>b>>c;
int ans=lcs3d(a,b,c);
cout<<ans;
return 0;
}
