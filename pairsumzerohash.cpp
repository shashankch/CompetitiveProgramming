
#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{

    int arr[] = {1, 3, -2, 6, -6, 2, 8};
    unordered_map<int, int> mypair;
    ///unordered_set<int> s; can also be done;
    for (int i = 0; i < 7; i++)
    {

        mypair[arr[i]] = arr[i];
    }
    int sum = 0;
    for (auto val : mypair)
    {

        if (mypair.find(sum - val.first) != mypair.end())
        {

            cout << "pairs are:" << val.first << "," << sum - val.first << endl;
        }
    }

    return 0;
}

/*
bool hasArrayTwoCandidates(int A[], int arr_size,
                           int sum)
{
    int l, r;

  Sort the elements
    sort(A, A + arr_size);

     Now look for the two candidates in
       the sorted array
    l = 0;
    r = arr_size - 1;
    while (l < r) {
        if (A[l] + A[r] == sum)
            return 1;
        else if (A[l] + A[r] < sum)
            l++;
        else // A[i] + A[j] > sum
            r--;
    }
    return 0;
}


*/
