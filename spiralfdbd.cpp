
#include <iostream>
using namespace std;

//void spiral_clock(int *arr,int r,int c){

//}

void spiral_anticlock(int arr[][10], int r, int c)
{
    int sc = 0, ec = c - 1;
    int sr = 0, er = r - 1;

    while (sc <= ec && sr <= er)
    {

        //top to bottom
        for (int i = sr; i <= er; i++)
        {
            cout << arr[i][sc] << ", ";
        }
        sc++;
        //left to right
        for (int j = sc; j <= ec; j++)
        {
            cout << arr[er][j] << ", ";
        }
        er--;
        //bottom to top
        if (sc <= ec)
        {
            for (int i = er; i >= sr; i--)
            {
                cout << arr[i][ec] << ", ";
            }
            ec--;
        }
        //right to left
        if (sr <= er)
        {
            for (int j = ec; j >= sc; j--)
            {
                cout << arr[sr][j] << ", ";
            }
            sr++;
        }
    }
    cout << "END";
}

int main()
{

    int r, c, arr[10][10];
    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {

            cin >> arr[i][j];
        }
    }

    //spiral_clock(arr,r,c);
    spiral_anticlock(arr, r, c);

    return 0;
}
