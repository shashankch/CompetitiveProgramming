

#include <iostream>
#include <stack>
using namespace std;

void stockspan(int arr[], int n)
{

    stack<int> s; /// here in stack we are pushing best day..with better values..in the previous.
    int ans[100] = {};
    for (int day = 0; day < n; day++)
    {

        int currprice = arr[day];
        while (s.empty() == false && arr[s.top()] < currprice)
        {
            s.pop();
        }
        int betterdvalue = s.empty() ? day + 1 : s.top();
        int span = day - betterdvalue;
        ans[day] = span;
        s.push(day);
    }

    for (int i = 0; i < n; i++)
    {

        cout << ans[i] << " ";
    }
}

int main()
{

    int n = 7;
    int arr[100] = {100, 80, 60, 70, 60, 75, 85};

    stockspan(arr, n);

    return 0;
}

/*


#include<iostream>
#include<stack>
using namespace std;


void stockspan(int arr[],int n){

    stack<int>s;  /// here in stack we are pushing best day..with better values..in the previous.
    int ans[100]={};
    for(int day=0;day<n;day++){

        int currprice=arr[day];
        while(s.empty()==false && arr[s.top()]<currprice){
            s.pop();
        }
        ans[day]=s.empty()?day+1:day-s.top();

        s.push(day);

    }


    for(int i=0;i<n;i++){

        cout<<ans[i]<<" ";
    }
cout<<"END";





}





int main(){

int n;
cin>>n;
int *arr=new int[n+1];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

stockspan(arr,n);


return 0;
}

*/
