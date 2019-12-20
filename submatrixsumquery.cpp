
#include<iostream>
using namespace std;


int submatrixsumquery(int **arr,int n,int m,int li,int lj,int bi,int bj){


    int sum=0;
///prefix sum calculation--------------->>>
    int prefix[n][m];
    prefix[0][0]=arr[0][0]; ///initialize first cell to first value.

    for(int i=1;i<m;i++){

        prefix[0][i]=prefix[0][i-1]+arr[0][i];/// add prefix sum for first row and columns...>>>
    }
    for(int i=1;i<n;i++){

        prefix[i][0]=prefix[i-1][0]+arr[i][0];
    }

    ///add prefix sum for rest rows and colns.
    for(int i=1;i<n;i++){

        for(int j=1;j<m;j++){

        /// upper part+left part+diagonalpart prefix sums for each cell.to calculate current cell prefix sum..
            prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+arr[i][j];
        }

    }

int vv=0,pp=0,qq=0,rr=0;
/////////////////////////////////////////////////////////////////////////


                       vv=prefix[bi][bj]; /// prefix sum upto (x,y) bottom right
                        if(li-1>=0){
                            pp=prefix[li-1][bj];  /// remove upper part not required..
                        }
                        if(lj-1>=0){
                            qq=prefix[bi][lj-1];  /// remove left not required part.
                        }
                        if(li-1>=0 && lj-1>=0){
                            rr=prefix[li-1][lj-1]; /// add cell removed twice above..
                        }


                        sum=sum+vv-pp-qq+rr;


    return sum;





}

int main(){

int q,n,m;
int li,lj,bi,bj;

cin>>n>>m;
cin>>q;
int **arr=new int*[n];

for(int i=0;i<n;i++){

    arr[i]=new int[m];
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
    }
}
while(q--){
    cin>>li>>lj;
    cin>>bi>>bj;
    cout<<submatrixsumquery(arr,n,m,li,lj,bi,bj)<<endl;

}



return 0;
}

/*
4 5
1
1 2 3 4 6
5 3 8 1 2
4 6 7 5 5
2 4 8 9 4
2 2
3 4
38

// Function to preprcess input mat[M][N].  This function
// mainly fills aux[M][N] such that aux[i][j] stores sum
// of elements from (0,0) to (i,j)
int preProcess(int mat[M][N], int aux[M][N])
{
   // Copy first row of mat[][] to aux[][]
   for (int i=0; i<N; i++)
      aux[0][i] = mat[0][i];

   // Do column wise sum
   for (int i=1; i<M; i++)
      for (int j=0; j<N; j++)
         aux[i][j] = mat[i][j] + aux[i-1][j];

   // Do row wise sum
   for (int i=0; i<M; i++)
      for (int j=1; j<N; j++)
         aux[i][j] += aux[i][j-1];
}













*/
