
#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> c(n);
        vector<ll> l(n);
        vector<ll> m(n);
        for (ll i = 0; i < n; i++)
        {
            ll cost;
            cin >> cost;
            c[i] = cost;
            if (i == 0)
            {
                m[i] = c[i];
            }
            else
            {
                m[i] = min(m[i - 1], c[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> l[i];
        }
        int finalcost = 0;
        /// int petrolavl=0;
        for (int i = 0; i < n; i++)
        {
            finalcost += l[i] * m[i];
        }
        cout << finalcost << endl;
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t,n,min,sum;
    cin>>t;
    while(t--)
    {
    cin>>n;
    int*c=new int[n];
    int*l=new int[n];
    for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++) cin>>l[i];
	min=c[0];sum=0;
	for(int i=0;i<n;i++)
	{
     if(c[i]<min)
	 min=c[i];
     sum=sum+min*l[i];
	}
	cout<<sum<<endl;
    }
	return 0;
}


*/
