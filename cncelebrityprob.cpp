#include <bits/stdc++.h>
using namespace std;

int celebrity(int **status, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int smallceleb = celebrity(status, n - 1);

    if (smallceleb != -1)
    {
        if (status[smallceleb][n] == 1 && status[n][smallceleb] == 0)
        {

            for (int i = 0; i < n; i++)
            {
                if (status[i][n] != 1)
                {
                    return -1;
                }
            }

            return n;
        }
        else if (status[smallceleb][n] == 0 && status[n][smallceleb] == 1)
        {
            //  for(int i=0;i<n-1;i++){
            //     if(status[i][smallceleb]!=1){
            //         return -1;
            //     }
            // }

            return smallceleb;
        }
    }
    return smallceleb;
}

int main()
{

    int n;
    cin >> n;
    int **status = new int *[n];

    for (int i = 0; i < n; i++)
    {
        status[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> status[i][j];
        }
    }

    cout << celebrity(status, n - 1) << endl;

    return 0;
}

