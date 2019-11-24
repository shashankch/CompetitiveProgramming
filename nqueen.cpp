
#include<iostream>
using namespace std;


/// function to check for safe pos in the board
    bool isafe(int board[10][10],int i,int j,int n){


            /// check for other queens in the upper column
            for(int row=0;row<i;row++){
                if(board[row][j]==1){
                    return false;
                }
            }

            /// check for the left upper diagonal

            int x=i;
            int y=j;
            while(x>=0 && y>=0){
                if(board[x][y]==1){
                    return false;
                }
                x--;
                y--;
            }
    /// check for the right upper diagonal

    x=i;
    y=j;
        while(x>=0 && y<n)
        {
         if(board[x][y]==1){
                    return false;
                }
                x--;
                y++;

        }

/// all safe
    return true;

    }

bool nqueen(int board[10][10],int i,int n){


        ///base case when all queens are placed row wise equals n
        if(i==n){

            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){

                    if(board[i][j]==1){
                        cout<<"Q ";
                    }
                    else{
                        cout<<"_ ";
                    }
                }
                cout<<endl;
            }
            cout<<endl;
/// here if program reaches the base case i.e place all n queens ....
///.....then print current configuration and return true and program terminates

        //return true;

        return false;
    ///  or  we can write ----->>> return false;
    /// if we want to print all possible configs of the queen on the board. .....
    ///.....program will not terminate after finding first ans and try to find all possible configs

        }

        /// now try to place queen in the current row columnwise
        for(int j=0;j<n;j++){

            if(isafe(board,i,j,n)){ /// queen is safe to place in that position .
                board[i][j]=1;
                /// call on the rest part of the board
                bool nextqueenrakhpaye=nqueen(board,i+1,n);
                if(nextqueenrakhpaye){
                    return true;
                }
                /// if reaches here that means not able to place queen
                 /// backtracking if next queen we were not able to place on the board
            board[i][j]=0;

            }


        }

/// program reaches here when there is no configuration ...
///...in the current row which is giving right for the next part of the board
return false;




}
int main(){


int n;
cin>>n;
int board[10][10];

if(nqueen(board,0,n))
{

    cout<<"YES"<<endl;
}






return 0;}
