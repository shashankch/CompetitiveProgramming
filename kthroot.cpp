#include<iostream>
#define ll long long int
using namespace std;

ll pow(ll no,ll exp){

ll res=1;
while(exp--){
   res*=no;
}


return res;

}



///https://www.geeksforgeeks.org/n-th-root-number/



int main(){

ll t,n,k,ans;
cin>>t;
while(t--){
    cin>>n>>k;
   ll s=0;
   ll e=n;
    while(s<=e){


      ll mid=(s+e)/2;
        if(pow(mid,k)==n){
            ans=mid;
            break;
        }
        else if(pow(mid,k)<n){
            ans=mid;
            s=mid+1;
        }
        else {
            e=mid-1;
        }
    }

    cout<<ans<<endl;
}
return 0;
}




/* solution
using namespace std;

int main()
{

    ll n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==1)
        {
            cout<<n<<endl;
            continue;
        }
        ll l=1,r=1000000,mid;
        while(l<r)
        {
            mid=l+r+1>>1;
            bool flag=1;
            ll tmp=1;
            for(int i=1;i<=k;i++)
            {
                tmp*=mid;
                if(tmp>n)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                l=mid;
            else
                r=mid-1;
        }
        cout<<r<<endl;
    }
    return 0;
}





*/





