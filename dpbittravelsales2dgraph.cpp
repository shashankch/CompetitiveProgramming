#include <iostream>
using namespace std;

#define INT_MAX 999999

int n = 4;
int dp[16][4];
// adj matrix which defines the graph..

int dist[10][10] = {

    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};
// if all cities have been visited..
int visited_all = (1 << n) - 1;
int tsp(int mask, int pos)
{

    if (mask == visited_all)
    {
        return dist[pos][0];
    }
    int ans = INT_MAX;
    // try to go the unvisited city..
    for (int city = 0; city < n; city++)
    {

        if ((mask & (1 << city)) == 0)
        {
            //city not visited..
            int newans = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newans);
        }
    }

    return ans;
}

int tspdp(int mask, int pos)
{

    if (mask == visited_all)
    {
        return dist[pos][0];
    }

    // look up
    if (dp[mask][pos] != -1)
    {

        return dp[mask][pos];
    }

    int ans = INT_MAX;
    // try to goto an unvisited city..
    for (int city = 0; city < n; city++)
    {

        if ((mask & (1 << city)) == 0)
        {
            int newans = dist[pos][city] + tspdp(mask | (1 << city), city);
            ans = min(ans, newans);
        }
    }
    return dp[mask][pos] = ans;
}

int main(int argc, char const *argv[])
{

    for (int i = 0; i < (1 << n); i++)
    {

        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }
    //Minimum weight hamiltonian path costs:
    cout << tspdp(1, 0) << endl;
    //cout<<tsp(1,0)<<endl;

    return 0;
}
