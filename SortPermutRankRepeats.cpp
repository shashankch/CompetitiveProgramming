
#include <iostream>
#include <cstring>
#include <set>
#include <cmath>
#include <vector>
#define ll long long int
#define MOD 1000003
using namespace std;

/*  ll fact(int k){


        if(k==0 || k==1){
            return 1;
        }
        return k*fact(k-1)%MOD;
    }

    */
ll fact(ll num)
{
    ll res = 1;
    for (ll i = 1; i <= num; i++)
    {
        res = (res * i) % MOD;
    }
    return res;
}

ll powfunc(ll base, ll power, ll mod)
{

    ll res = 1;
    base = base % mod;
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            res = (res * base) % mod;
        }
        power = power >> 1;
        base = (base * base) % mod;
    }

    return res;
}

void rankduplicate(string str)
{

    int n = str.length();
    int ans = 1;
    for (int i = 0; i < n; i++)
    {

        /// count lesser no.of character
        int small = 0;
        for (int j = i + 1; j < n; j++)
        {

            if (str[i] > str[j])
            {
                small++;
            }
        }

        /// calculate frequency of character to remove duplicates
        vector<int> freq(256, 0);
        for (int k = i; k < n; k++)
        {

            freq[str[k] - 'a']++;
        }

        int dupface = 1;
        for (int element : freq)
        {
            dupface *= fact(element) % MOD;
        }

        ans += (fact(n - i - 1) % MOD * small) % MOD * powfunc(dupface, MOD - 2, MOD) % MOD;
    }

    cout << ans % MOD % MOD;
}

void getrank(string str, int i, string cpy, set<string> &s)
{

    if (i == str.length())
    {

        s.insert(str);

        /// decide what to do
    }

    for (int j = i; j < str.length(); j++)
    {

        swap(str[i], str[j]);
        getrank(str, i + 1, cpy, s);
    }
}

int main()
{

    string str;
    cin >> str;
    /*
    string cpy=str;
    set<string>s;
    getrank(str,0,cpy,s);
    int cnt=1;
    for(auto i=s.begin();i!=s.end();i++){
        if(*i==str){
            cout<<cnt<<endl;
            break;
        }
        cnt++;
    }
*/
    rankduplicate(str);

    return 0;
}
