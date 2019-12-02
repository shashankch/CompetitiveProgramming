
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;

void subs(int s[],int a[],int i,int j,int n,int t){
   	set <int> f;// set declared
	set<int>::iterator itr;  //set iterator
	if(i==n){
		int sum=0;
		for(int k=0;k<j;k++){
			sum+=a[k];
		}
		if(sum==t){
		sort(a,a+j);
        for(int k=0;k<j;k++)
		 f.insert(a[k]);
		 for(itr=f.begin();itr!=f.end();itr++)    ///
   cout<<*itr<<" ";                    ///Using set to print
		cout<<endl;
	    }
		return;
	}
	subs(s,a,i+1,j,n,t);
	a[j]=s[i];
	subs(s,a,i+1,j+1,n,t);

}
////////////////////////////////////////////////////////////////////////////////////
void sum_it_up(int *arr, int be, int en, int *osf, int k, int sum, int key) {
	if (be > en) return;
	if (sum == key) {
		print(osf, k);
		cout << endl;
		return;
	}
	osf[k] = arr[be];
	sum_it_up(arr, be + 1, en, osf, k + 1, sum + arr[be], key);
	osf[k] = 0;
	sum_it_up(arr, be + 1, en, osf, k + 1, sum, key);
	osf[k] = 0;
}

////////////////////////////////////////////////////////////////////////////////

int n,sum=0;
void find(int a[],int i,int k,int s,int ans[]){
    //Base Case
     if(sum==s){
        for(int j=0;j<k;j++)
            cout<<ans[j]<<" ";
            cout<<endl;
        return;
     }
     if(i==n)
        return;
     //Recursive Case
       if(a[i]<=s){
          ans[k]=a[i];
          sum+=a[i];
         find(a,i+1,k+1,s,ans);
          sum-=a[i];
       }
        find(a,i+1,k,s,ans);
}


///////////////////////////////////////////////////////////////////////
set<vector<int> > finalResult;
void sumitup(int ar[100],int start,int end,int sum,int target,vector<int> output){
    if(start==end){
       return;

    }
    if(sum==target){
         for(int i=0;i< output.size();i++){
			cout << output[i] << " ";
		}
        cout<<endl;
        finalResult.insert(output);
        return;
    }
    if(sum>target) return;

    vector<int> temp = output;
    temp.push_back(ar[start]);

    sumitup(ar,start+1,end,sum+ar[start],target,temp);
    sumitup(ar,start+1,end,sum,target,output);
    return ;

}
/// sum it up using bitsets approach........................................>>>>>>>>
#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
tree_order_statistics_node_update>
new_data_set;

const ll N=100005;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // ll t;
    // cin>>t;
    // while(t--)
    {
        ll i,j,k,n,m,ans=0,cnt=0,sum=0;
        cin>>n;
        ll a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>k;
        sort(a,a+n);
        m=pow(2,n);
        vector<vector<ll>> vv;
        for(i=1;i<m;i++){
            ll ii=i;vector<ll> v;
            cnt=0;j=0;
            while(ii){
                if(ii&1){
                    cnt+=a[j];
                    v.pb(a[j]);
                }
                ii/=2;
                j++;
            }
            if(k==cnt){
                if(binary_search(vv.begin(), vv.end(),v)){
                    continue;
                }
                vv.pb(v);
                sort(vv.begin(), vv.end());
            }
        }
        for(auto v:vv){
            for(auto x:v){
                cout<<x<<" ";
            }cout<<'\n';
        }
    }
}

/////////////////////////////////////////////////////////////////////////


int main(){


        int n;
        cin>>n;
        int arr[n];

    for(int i=0;i<n;i++){

        cin>>arr[i];
    }
    sort(arr,arr+n);
int target;
cin>>target;
//vector<vector<int> > bigv;
//vector<int> vs;
//sumitup(arr,n,0,target,vs,bigv);


return 0;
}
