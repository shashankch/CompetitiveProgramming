
#include <iostream>

using namespace std;

bool solvemaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n)
{

    /// base case when current position reaches to destination
    if (i == m && j == n)
    {

        soln[m][n] = 1;
        /// print path
        for (int p = 0; p <= m; p++)
        {
            for (int q = 0; q <= n; q++)
            {
                cout << soln[p][q] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }
    /// if current position is beyond the maze then
    if (i > m || j > n)
    {
        return false;
    }

    /// if current position is not blocked position in the maze.
    if (maze[i][j] == 'X')
    {
        return false;
    }

    /// marking the position -->assuming the current position leads to solution to the maze.
    soln[i][j] = 1;

    /// recursive cases --- calling for the rest of the maze

    /// check for right path
    bool rightresult = solvemaze(maze, soln, i, j + 1, m, n);
    /// check for the down path
    bool downresult = solvemaze(maze, soln, i + 1, j, m, n);

    ///====>>>>> BACKTRACK CODE returning path set all back to zero same state;

    soln[i][j] = 0;

    ///check if anyone leads to the solution
    if (rightresult || downresult)
    {
        return true;
    }
    /// both right and down no success no path is possible
    return false;
}
int main()
{

    char maze[10][10] = {

        "0000",
        "00X0",
        "000X",
        "0X00"

    };

    int soln[10][10] = {0};

    int m, n;
    cin >> m >> n;

    if (solvemaze(maze, soln, 0, 0, m - 1, n - 1) == false)
    {
        cout << "Sorry path does not exists!";
    }

    return 0;
}
