#include <bits/stdc++.h>

using namespace std;
// priority queue using heap which is complete binary tree and follows heap property..
//min heap
class PriorityQueue
{

    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {

        return pq.size() == 0;
    }

    // return the size of priority q no of elements present..
    int getsize()
    {

        return pq.size();
    }

    int getmin()
    {

        if (isEmpty())
        {
            return 0; //pq is empty..
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childindex = pq.size() - 1;
        int parentIndex = (childindex - 1) / 2;

        while (childindex > 0)
        {
            if (pq[childindex] < pq[parentIndex])
            {
                int temp = pq[childindex];
                pq[childindex] = pq[parentIndex];

                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childindex = parentIndex;
        }
    }

    // int removemin(){

    //     if(isEmpty()){

    //     }

    // }
};

void ksortedArray(int input[],int n,int k){

    priority_queue<int> pq;
    for (int i = 0; i < k;i++){
        pq.push(input[i]);
    }
    int j = 0;
    for (int i = k; i < n;i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }


    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}










int main()
{

    priority_queue<int> p;

    p.push(100);
    p.push(21);
    p.push(7);

    cout << p.size() << endl;
    cout << p.empty() << endl;
    cout << p.top() << endl;

    while (!p.empty())
    {
        cout << p.top() << endl;
        p.pop();
    }
    return 0;
}