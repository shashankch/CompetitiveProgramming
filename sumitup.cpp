#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;



void subset(int *arr,int n,int i,int sum,int target,vector<int>&ans,set<vector<int> >&st){


        if(i==n){

            if(sum==target){

            st.insert(ans);



            }
            return ;
        }

        int temp=sum;
   		 sum+=arr[i];
   		 ans.push_back(arr[i]);
            subset(arr,n,i+1,sum,target,ans,st);


        sum=temp;
       ans.pop_back();
     subset(arr,n,i+1,sum,target,ans,st);
}










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
vector<int> v;
set<vector<int> > st;

//set<vector<int> > :: iterator sitr;
//vector<int> :: iterator vitr;

   subset(arr,n,0,0,target,v,st);

   for(auto sitr=st.begin() ; sitr!=st.end();++sitr){

        for(auto vitr = (*sitr).begin();vitr!=(*sitr).end();vitr++){
            cout<<*vitr<<" ";
        }
        cout<<endl;
   }




return 0;
}

///solution..

/*
Algorithm:

Sort the array(non-decreasing).
First remove all the duplicates from array.
Then use recursion and backtracking to solve the problem.
1. If at any time sub-problem sum == 0 then add that array to the result (vector of vectors).
2. Else if sum if negative then ignore that sub-problem.
3. Else insert the present array in that index to the current vector and call the function with sum = sum-ar[index] and index = index, then pop that element from current index (backtrack) and call the function with sum = sum and index = index+1


#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 #define fio ios_base::sync_with_stdio(false)

#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)

#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)

#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

// TRY SOLVING IT AGAIN NEXT TIME AND MUST LOOK AT THE EDITORIAL  SOLUTION

vector<vector<int> >ans;
set<vector<int> > mp;
int B;

void solve(vector<int> &A,int i,int req,vector<int> st){
    if(i>A.size() or req<0)return ;

    if(req==0){
        if(!st.empty() and mp.find(st)==mp.end()){
            mp.insert(st);
            ans.push_back(st);
        }
    }

    if(i==A.size())return;

    st.push_back(A[i]);
    solve(A,i+1,req-A[i],st);
    st.pop_back();

    solve(A,i+1,req,st);

    vector<int> st2;
    st2.push_back(A[i]);
    solve(A,i+1,B-A[i],st2);
}


vector<vector<int> > combinationSum(vector<int> &A, int B) {
    ans.clear();
    mp.clear();
    ::B=B;
    if(A.size()==0 or B==0)return ans;
    sort(A.begin(),A.end());
    vector<int> st;
    solve(A,0,B,st);
    sort(ans.begin(),ans.end());
    return ans;
}
*/





