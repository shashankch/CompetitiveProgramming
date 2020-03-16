#include<iostream>
#include<climits>
using namespace std;

int maxsumsubmatrix(int **arr,int n,int m){

    //col add
    for(int i=n-1;i>=0;i--){
        for(int j=m-2;j>=0;j--){

            arr[i][j]+=arr[i][j+1];
        }
    }

    //row add
    for(int i=m-1;i>=0;i--){
        for(int j=n-2;j>=0;j--){

            arr[j][i]+=arr[j+1][i];
        }
    }

    int result=INT_MIN;
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            result=max(result,arr[i][j]);
        }
    }


        return result;
        
        }

int main(int argc, char const *argv[])
{
   

   int n,m;
   cin>>n>>m;

   int **arr=new int *[n];
   for(int i=0;i<n;i++)
   {

       arr[i]=new int[m];


   }

   for(int i=0;i<n;i++){

       for(int j=0;j<n;j++){
           cin>>arr[i][j];
       }

   }

   cout<<maxsumsubmatrix(arr,n,m)<<endl;




    return 0;
}

/*

3 3
-5 -4 -1
-3 2 4
2 5 8
19

*/