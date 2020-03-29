
#include <iostream>
using namespace std;
int board[10][10];
int high = 0;

void knighttourmaxvisited(int r, int c, int count)
{

	if (r < 0 || c < 0 || r >= 10 || c >= 10 || board[r][c] == 0)
	{
		return;
	}

	board[r][c] = 0;

	high = max(high, count + 1);
	knighttourmaxvisited(r - 2, c - 1, count + 1);
	knighttourmaxvisited(r - 2, c + 1, count + 1);
	knighttourmaxvisited(r - 1, c - 2, count + 1);
	knighttourmaxvisited(r - 1, c + 2, count + 1);
	knighttourmaxvisited(r + 1, c - 2, count + 1);
	knighttourmaxvisited(r + 1, c + 2, count + 1);
	knighttourmaxvisited(r + 2, c - 1, count + 1);
	knighttourmaxvisited(r + 2, c + 1, count + 1);

	board[r][c] = 1;
}
////////////////////////////////////////////////////////////////////
/*
#include<iostream>
using namespace std;

int ans[10][10]={0};

void KnightMoves(int board[][10],int r,int c,int n)
{
    if(ans[r][c]!=0)
	{
		return;
	}

	if(board[r][c]!=1)
	{
		return;
	}

	if(r>=n || c>=n || r<0 || c<0 )
	  return;

	ans[r][c]=1;
	KnightMoves(board,r-2,c-1,n);
	KnightMoves(board,r-2,c+1,n);
	KnightMoves(board,r-1,c+2,n);
	KnightMoves(board,r-1,c-2,n);
	KnightMoves(board,r+1,c-2,n);
	KnightMoves(board,r+1,c+2,n);
	KnightMoves(board,r+2,c-1,n);
	KnightMoves(board,r+2,c+1,n);

}

int main() {
	int n;
	cin>>n;
	int board[10][10];
     for(int i=0;i<n;i++)
	 {
         for(int j=0;j<n;j++)
		 {
			 cin>>board[i][j];
		 }
	 }

	KnightMoves(board,0,0,n);
	int count=0;
	 for(int i=0;i<n;i++)
	 {
         for(int j=0;j<n;j++)
		 {
			 if(!ans[i][j])
			   count++;
		 }
	 }
	 cout<<count;
	return 0;
}


*/
//////////////////////////////////////////////////////////////////

/*
#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<vector<int>> &v,int i,int j,int x[],int y[],vector<vector<int>> &a)
{
	if(i>=n || i<0 || j>=n || j<0)
	return 0;

    if(a[i][j]!=0)     // reusing the value that we have calculated - possible cells that can be occupied from (i,j)
    return a[i][j];

    if(v[i][j]==0)     // return 0 if knight can't land on that cell
	return 0;

    int c=0;           // initializing counter
    v[i][j]=0;         // making v[i][j]=0 so  that it can't be visited again while we are calculating maximum cells occupied from (i,j) since moving in one direction.
	for(int k=0;k<8;k++)
	{
        c=max(c,f(n,v,i+x[k],j+y[k],x,y,a));  // assigning  counter maximum value calculated from all possible directions
	}
    v[i][j]=1;                              // again making v[i][j]=1 , since once calculated knight can visit and use the calculated value if required , if it visits i,j from other way
	return a[i][j]=c+1;                     // (+1)  since (i,j) is also occupied that is not counted in c
}

int main() {
	int n;
	cin>>n;
	vector<vector<int>> v(n,vector<int>(n));
	int x[]={-2,-2,-1,-1,+1,+1,+2,+2};
	int y[]={-1,+1,-2,+2,-2,+2,-1,+1};
	int c1=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>v[i][j];
            if(v[i][j]==1)
            c1++;
		}
	}

    vector<vector<int>> a(n,vector<int>(n,0));    // vector that stores value of maximum cells that can be occupied from (i,j)

    cout<<c1-f(n,v,0,0,x,y,a)<<endl;;

	return 0;
}

*/
int main()
{

	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j])
			{
				sum++;
			}
		}
	}

	knighttourmaxvisited(0, 0, 0);

	cout << sum - high << endl;
}
