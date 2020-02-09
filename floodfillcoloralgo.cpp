// flood fill is variant of bfs/dfs used to label(color) the various connected
//compoent present in the graph..performed on implicit graph(2dmatrices)

// call dfs on the neighbouring cells 4-8 directions including diagonals until we hit the boundary..
//recursively call and then hit the boundary and backtrack..
#include<iostream>
using namespace std;

int R,C;

    void printMat(char input[][50]){

        for(int i=0;i<R;i++){

            for(int j=0;j<C;j++){
                cout<<input[i][j];
            }
            cout<<endl;
        }

    }





// W N E S directions..
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
//ch is the character to be replaced..
// color is the character to be added..
void floodfill(char mat[][50],int i,int j,char ch,char color){

    //base case---matrix boundary
    if(i<0 || j<0 || i>=R || j>=C){
            return;
    }


    // figure boundary condition
    if(mat[i][j]!=ch){
        return;
    }

    



    //recursive call..
    mat[i][j]=ch; // coloring..

    // check for the intermediate state..
    printMat(mat);
    cout<<endl;

    for(int k=0;k<4;k++){
        floodfill(mat,i+dx[k],j+dy[k],ch,color);
    }

}

int main(){

    
    cin>>R>>C;
    char input[15][50];

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>input[i][j];
        }
    }

    printMat(input);
    floodfill(input,8,13,'.','r');
    printMat(input);
    return 0;

}