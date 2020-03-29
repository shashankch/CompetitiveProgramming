
#include <bits/stdc++.h>
#include <vector>
using namespace std;

/// implementation of max heap i.e priority of parent>child..

void upheapify(vector<int> &heap, int idx)
{

    /// if heap /vector is empty
    if (idx == 0)
    {
        return;
    }

    /// now calculate parent of the current element added i.e idx
    int parentidx = (idx - 1) / 2;
    if (heap[parentidx] < heap[idx])
    {
        int temp = heap[parentidx];
        heap[parentidx] = heap[idx];
        heap[idx] = temp;
        /// recursively move up the tree ..root.. here parent index is sent because it is now current index
        upheapify(heap, parentidx);
    }
    else
    {
        return;
    }
}

void insert(vector<int> &heap, int key)
{

    /// push element at last of the vector..
    heap.push_back(key);
    /// call on the upheapify to maintain complete binary tree..
    upheapify(heap, heap.size() - 1);
}

void display(vector<int> &heap)
{

    for (int i = 0; i < heap.size(); i++)
    {
        cout << heap[i] << " ";
    }
    cout << endl;
}

void downheapify(vector<int> &heap, int idx)
{

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    /// to ensure it has right and left child and within the array range..
    if (left >= heap.size() and right >= heap.size())
    {
        return;
    }

    /// index of the largest value index
    int largestidx = idx;

    /// check for left and right child for highest priority.. to replace the root..
    if (left < heap.size() and heap[left] > heap[largestidx])
    {
        largestidx = left;
    }
    if (right < heap.size() and heap[right] > heap[largestidx])
    {
        largestidx = right;
    }
    /// if root has highest priority then do nothing..
    if (largestidx == idx)
    {
        return;
    }

    /// swap with the highest child ..
    swap(heap[idx], heap[largestidx]);
    /// call recursively to left and right tree.. where largest index
    downheapify(heap, largestidx);
}
///delete root/highest priority element here first swap with the last and first element and then downheapify.
void deletepeak(vector<int> &heap)
{

    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    downheapify(heap, 0);
}

///unoptimized approach : O(nlogn)
void buildheapfromgiven(vector<int> &heap)
{

    for (int i = 0; i < heap.size(); i++)
    {
        upheapify(heap, i);
    }
}
/// optimized approach: O(n)
/// considering right part will be heap
void buildheapfromgivenoptimal(vector<int> &heap)
{

    for (int i = heap.size() - 1; i >= 0; i--)
    {
        downheapify(heap, i);
    }
    cout << endl;
}
/// O(logn+logn) : first insert infinity at delete index then upheapify then perform delete at root technique..
void deletefromanypos(vector<int> &heap, int idx)
{

    heap[idx] = INT_MAX;
    upheapify(heap, idx);
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    downheapify(heap, 0);
}

/// helper downheapify function : here heapsize is passed because after each swap arr.size is reduced..
void downheapifyhelper(vector<int> &heap, int idx, int heapsize)
{

    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    /// to ensure it has right and left child and within the array range..
    if (left >= heapsize and right >= heapsize)
    {
        return;
    }

    /// index of the largest value index
    int largestidx = idx;

    /// check for left and right child for highest priority.. to replace the root..
    if (left < heapsize and heap[left] > heap[largestidx])
    {
        largestidx = left;
    }
    if (right < heapsize and heap[right] > heap[largestidx])
    {
        largestidx = right;
    }
    /// if root has highest priority then do nothing..
    if (largestidx == idx)
    {
        return;
    }

    /// swap with the highest child ..
    swap(heap[idx], heap[largestidx]);
    /// call recursively to left and right tree.. where largest index
    downheapifyhelper(heap, largestidx, heapsize);
}

/// O(nlogn) : inplace and not stable sort(relative order of elements is not maintained).. here selection takes O(1) time instead of O(n)

/// here first build heap using array..by downheapify for optimized way..
/// then reduce size of array by performing swap of first and last element and downheapification..

void heapsort(vector<int> &arr)
{

    int heapsize = arr.size();
    buildheapfromgivenoptimal(arr);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapsize -= 1;
        downheapifyhelper(arr, 0, heapsize);
    }
}

int main()
{

    vector<int> heap;
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {

        cin >> x;
        /// insert(heap,x);
        heap.push_back(x);
    }
    display(heap);
    ///buildheapfromgiven(heap);
    ///buildheapfromgivenoptimal(heap);
    heapsort(heap);

    ///deletepeak(heap);
    display(heap);
    ///deletefromanypos(heap,3);
    ///display(heap);

    return 0;
}
