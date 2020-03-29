

#include <iostream>
using namespace std;

void piyush_park(int n, int m, int k, int s, char arr[101][101])
{
    int mx = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == '.' && s >= k)
            {
                if (j != m - 1)
                {
                    s = s - 3;
                }
                else
                {
                    s = s - 2;
                }
            }
            else if (arr[i][j] == '*' && s >= k)
            {
                if (j != m - 1)
                {
                    s = s + 4;
                }
                else
                {
                    s = s + 5;
                }
            }
            else if (arr[i][j] == '#' && s >= k)
            {

                // s=s-1;

                break;
            }
        }
    }

    if (s >= k)
    {

        cout << "Yes" << endl;
        cout << s;
    }

    else
    {

        cout << "No" << endl;
    }
}

int main()
{

    int n, m, k, s;
    char arr[101][101];

    cin >> n >> m >> k >> s;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    piyush_park(n, m, k, s, arr);

    return 0;
}
