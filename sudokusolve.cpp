


#include<iostream>
#include<cmath>
using namespace std;


bool canPlace(int mat[][9],int i,int j,int n,int number){


    /// check for row and column for possible number to avoid duplicate..
    for(int z=0;z<n;z++){

        if(mat[z][j]==number || mat[i][z]==number){
            return false;
        }
        }


        /// check for subgrid if no is duplicate ...
        /// formula: [i/sqrt n]*sqrt n ----------> i/sqrt n : gives the coordinates of the subgrid in the sudoku..
        int rn=sqrt(n);
        int startx=(i/rn)*rn;
        int starty=(j/rn)*rn;

           for(int p=startx;p<startx+rn;p++){
            for(int q=starty;q<starty+rn;q++){

                if(mat[p][q]==number){
                    return false;
                }
            }

        }




return true;

}
bool solvesudoku(int mat[][9],int i,int j,int n){


    /// base case when place along the column row by row moving to right direction
    if(i==n){



        /// print the sudoku......solved !!

        for(int p=0;p<n;p++){
            for(int q=0;q<n;q++){
                cout<<mat[p][q]<<" ";
            }
            cout<<endl;
        }





        return true;
    }

    /// case when current position is beyond the matrix reaches the end of the column
    if(j==n){
            /// call on the next row .. i+1 and j=0
        return solvesudoku(mat,i+1,0,n);
    }
    /// check for pre filled numbers skip those cells...move j+1
    if(mat[i][j]!=0){
        return solvesudoku(mat,i,j+1,n);
    }

    ///Recursive case
    /// try for all possible numbers from 1 to n
    for(int number=1;number<=n;number++){

            if(canPlace(mat,i,j,n,number)){
             /// placing the number assuming that we could solve the sudoku.
                mat[i][j]=number;
                /// calling the next left part of the sudoku for solution...
                bool nextpart=solvesudoku(mat,i,j+1,n);
                if(nextpart==true){
                    return true;
                }
            }

        /// trying all possible number in the current cell for possible solution to sudoku....
    }
/// BACKTRACK ----->>>> if all numbers is not leading to the solution ...
///then we backtrack and return false and change current cell back to zero..0
    mat[i][j]=0;

/// return false for no possible nos. placed giving result--> back to previous cell....
return false;


}

int main(){


int mat[9][9]={

{5,3,0,0,7,0,0,0,0},
{6,0,0,1,9,5,0,0,0},
{0,9,8,0,0,0,0,6,0},
{8,0,0,0,6,0,0,0,3},
{4,0,0,8,0,3,0,0,1},
{7,0,0,0,2,0,0,0,6},
{0,6,0,0,0,0,2,8,0},
{0,0,0,4,1,9,0,0,5},
{0,0,0,0,8,0,0,7,9},


};
solvesudoku(mat,0,0,9);
return 0;
}
