


#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;


/// approach 3: here check for each element if element-1 exists or not if exist then it is not left boundary
/// we continue else we run loop from lb to rb.. and increment counter and keep max..
/// first insert all element in the map/set..
/// O(N) here every element is visited twice..
int longestconsecutiveseq(int *arr,int n){

    unordered_set<int>s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    int ans=0;
    for(int i=0;i<n;i++){

        if(s.find(arr[i]-1)!=s.end()){
            continue;
        }
        else{
            int count=0;
            int x=arr[i];  /// left boundary
            while(s.find(x)!=s.end()){

                    count++;
                    x++;

            }
            ans=max(ans,count);
        }
    }

    return ans;

}










/// approach 2: using track of left and right boundary and keeping track of streak.. and updating
/// lb and rb boundary when new element is added..store streak length of element in the map..
/// O(n) and O(n) time and space..
void longestsubconsecutive(int *arr,int n){

    unordered_map<int,int>m;
  //  m[arr[0]]=1;
  //  m[arr[1]]=1;
    ///m.insert(arr[1],1);
    for(int i=0;i<n;i++){

        int rb=arr[i]-1;
        int lb=arr[i]+1;
        int streak=0;
        int len1=0;
        int len2=0;
        /// case 1: if rb is present
        if(m.find(rb)!=m.end()){

               len1=m[rb];



        }


        /// case 2: if lb is present
        if(m.find(lb)!=m.end()){

            len2 = m[lb];

        }


        /// case 3: if lb and rb both are present

        streak=len1+len2+1;
        m[arr[i]]=streak;
       if(len1!=0){
         m[arr[i]-len1]=streak;
       }
       if(len2!=0){
         m[arr[i]+len2]=streak;
       }


    }

   for(auto i:m){

      cout<<i.first<<" "<<i.second<<endl;

  }






}

/// approach 1: O(max-min)
/// O(n) space
void longestconsecutivelength(int *arr, int n){


        int mx=INT_MIN;
        int mi=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]>mx){
            mx=arr[i];
        }
        if(arr[i]<mi){
            mi=arr[i];
        }

    }
    cout<<"max:"<<mx<<endl;
    cout<<"min:"<<mi<<endl;
    unordered_set<int>s;

    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int count=0;
    int ans=0;
    for(int i=mi;i<=mx;i++){

        if(s.find(i)!=s.end()){
            count++;
        }
        else{
            ans=max(ans,count);
            count=0;
        }
    }
    cout<<count;





}




int main(){

int n;
cin>>n;
int *arr=new int[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
//longestsubconsecutive(arr,n);
//cout<<len<<endl;
//cout<<"length:"<<longestconsecutiveseq(arr,n);
longestconsecutivelength(arr,n);

return 0;
}


