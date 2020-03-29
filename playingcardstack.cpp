
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int prime(int k)
{

    int pr[1000] = {0};

    pr[0] = pr[1] = 0;
    pr[2] = 1;
    for (int i = 3; i <= 1000; i += 2)
    {

        pr[i] = 1;
    }
    for (int i = 3; i <= 1000; i += 2)
    {

        if (pr[i])
        {
            for (int j = (i * i); j <= 1000; j += 2 * i)
            {
                pr[j] = 0;
            }
        }
    }

    int cnt = 0;
    for (int i = 2; i <= 1000; i++)
    {

        if (pr[i])
        {
            cnt++;
        }
        if (cnt == k)
        {
            return i;
        }
    }
}
int main()
{

    int n, q;
    cin >> n >> q;
    vector<stack<int>> b(1000), a(1000);
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        a[0].push(val);
    }

    for (int i = 1; i <= q; i++)
    {

        while (!a[i - 1].empty())
        {
            val = a[i - 1].top();
            a[i - 1].pop();
            val % prime(i) == 0 ? b[i].push(val) : a[i].push(val);
        }
    }

    for (int i = 1; i <= q; i++)
    {
        while (!b[i].empty())
        {
            val = b[i].top();
            cout << val << " ";
            b[i].pop();
        }
    }

    while (!a[q].empty())
    {
        val = a[q].top();
        cout << val << " ";
        a[q].pop();
    }
    return 0;
}

/*
stack<int> a,b,c;
for(int i=0;i<n;i++){
    cin>>val;
    a.push(val);
}
for(int i=1;i<=q;i++){



 if(a.empty()){
    break;
 }

 int curp=prime(i);
 while(!a.empty()){
int val=a.top();
 a.pop();

    if(val%curp==0){
        b.push(val);
    }
    else{
        c.push(val);
    }

 }
 while(!b.empty()){
    cout<<b.top()<<endl;
    b.pop();
 }

 while(!c.empty()){
     cout<<c.top()<<endl;
    a.push(c.top());
    c.pop();
 }


}
while(!a.empty()){
 cout<<a.top()<<endl;
   a.pop();
}

*/
