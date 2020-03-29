
#include <bits/stdc++.h>
using namespace std;

int sanket_string(string s, int n, int k)
{

    string temp = s;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {

        if (temp[i] != temp[i + 1] && k > 0)
        {
            temp[i + 1] = temp[i];
            k--;
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (temp[i] == temp[i + 1])
        {
            ans++;
        }
    }

    return ans + 1;
}

int sanstring(string s, int n, int k)
{

    int freq[2] = {0};
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        if (min(freq[0], freq[1]) > k)
        {
            freq[s[i] - 'a']++;
        }
        else
        {
            ans++;
        }
    }

    return ans;
}

int sanket(string s, int n, int k)
{

    char temp = 'a';
    int j = k;
    for (int i = 0; i < n; i++)
    {

        if (s[i] != temp && j > 0)
        {
            swap(s[i], temp);
            j--;
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != temp)
        {
            mx = 0;
            continue;
        }
        mx++;
    }

    char temp2 = 'b';
    j = k;
    for (int i = 0; i < n; i++)
    {

        if (s[i] != temp2 && j > 0)
        {
            swap(s[i], temp2);
            j--;
        }
    }
    int mx2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != temp2)
        {
            mx2 = 0;
            continue;
        }
        mx2++;
    }

    return max(mx, mx2);
}
//Solution --------------------------------------------------->>>>>>>>>>>>>>
int findLen(string &A, int n, int k, char ch)
{
    int maxlen = 1;
    int cnt = 0;
    int l = 0, r = 0;

    // traverse the whole string
    while (r < n)
    {

        /* if character is not same as ch
           increase count */
        if (A[r] != ch)
            ++cnt;

        /* While  count > k  traverse the string
           again until count becomes less than k
           and decrease the count when characters
           are not same */
        while (cnt > k)
        {
            if (A[l] != ch)
                --cnt;
            ++l;
        }

        /* length of substring will be rightIndex -
           leftIndex + 1. Compare this with the maximum
           length and return maximum length */
        maxlen = max(maxlen, r - l + 1);
        ++r;
    }
    return maxlen;
}

// function which returns maximum length of substring
int answer(string &A, int n, int k)
{
    int maxlen = 1;
    for (int i = 0; i < 26; ++i)
    {
        maxlen = max(maxlen, findLen(A, n, k, i + 'A'));
        maxlen = max(maxlen, findLen(A, n, k, i + 'a'));
    }
    return maxlen;
}
//https://www.geeksforgeeks.org/maximum-length-substring-having-all-same-characters-after-k-changes/

int main()
{
    int k;
    cin >> k;
    string a;
    cin >> a;
    int n = a.length();
    // cout<<sanket_string(a,n,k);
    cout << sanket(a, n, k);
    return 0;
}
