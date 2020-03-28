#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    int arr[] = {20, 30, 40, 40, 40, 50, 100, 1100};
    int n = sizeof(arr) / sizeof(int);
    //find function
    int key = 40;
    auto it = find(arr, arr + n, key);
    cout << it << endl;
    // returns the address of the found element.

    // to get the index
    cout << it - arr << endl;

    if (it - arr == n)
    {
        cout << "element not present";
    }
    else
    {
        int index = it - arr;
        cout << index << endl;
    }

    bool present = binary_search(arr, arr + n, key);

    if (present)
    {
        cout << "hurray! found it..";
    }
    else
    {
        cout << "not found";
    }

    // get the index of the element..
    //lower_bound(s,e,key) and upper_bound(s,e,key)
    // lower bound returns the index of the element greater than equal to key..
    auto lb = lower_bound(arr, arr + n, 40);
    cout << endl
         << "lower bound of 40 is" << lb - arr << endl;

    //upper bound returns the first striclty greater than key..

    auto ub = upper_bound(arr, arr + n, 40);
    cout << endl
         << "Upper bound of 40 is" << ub - arr << endl;

    // if(it-arr==n){
    //     cout<<"element not present"<<endl;
    // }

    // no. of elements present b/w and used to find freq of  key element.
    cout << "occ freq of key is " << ub - lb << endl;
    // check freq to determine element is present or not because upper bound==lower bound in such cases.

    // sort an array using sort() function
    int nn = 10;
    int ar[10];
    sort(ar, ar + nn);

    // rotate containers
    int rr[] = {10, 20, 30, 40, 50};
    int ns = sizeof(rr) / sizeof(int);
    rotate(rr, rr + 2, rr + ns);
    //start mid end

    for (int i = 0; i < ns; i++)
    {
        cout << rr[i] << " ";
        //output 30,40,50,10,20
    }
    cout << endl;
    vector<int> v{10, 20, 30, 40, 50};
  

    rotate(v.begin(),v.begin()+2,v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout<<endl;
    //next permutation : next lexicographically bigger number

    next_permutation(v.begin(),v.end());
    for(int x:v){
        cout<<x<<" ";
    }

// swap(a,b) max(a,b) min() reverse(a,a+index);
    
    vector<int>test;
    vector<int> test2(5,0);  // size is 5 int and value is 0
    vector<int> test3(test2.begin(),test2.end());
    
    vector<int> test4{ 1,2,3,10,14};

    // auto 
    //v.size()  {no of elements}
    // for(int x:vector)
    // vector<int>:: iterator it;
    //v.capacity() {size of the underlying array} 
    // v.max_size()  {max no. of elements a vector can hold in the worst case acc. to avbl memory.}
    // doubling of memory is expensive operation..  
    // push_back pop_back()  in O(1)
    // d.insert(d.begin()+3,4,100);  insert(index,freq,value to insert);  in o(n)
    //d.erase(d.begin()+2,d.begin()+5)
    //d.resize(18)  size is will increase in case of increase..

//d.clear() clear all elements but not the vector.
//d.empty()
// d.front()  front element d.back() back element..
//to avoid doubling use reserve function.. v.reserve(2000)
    return 0;
}