
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int median = 0;
priority_queue<long long int> maxHeap;
priority_queue<long long int, vector<long long int>, greater<long long int>> minHeap;
void median2()
{
	if (maxHeap.size() == minHeap.size())
	{
		long long int sum = maxHeap.top() + minHeap.top();
		long long int average = sum / 2;
		median = average;
		return;
	}
	else if (maxHeap.size() - minHeap.size() == 1)
	{
		median = maxHeap.top();
		return;
	}
	else if (minHeap.size() - maxHeap.size() == 1)
	{
		median = minHeap.top();
		return;
	}
	else if (maxHeap.size() - minHeap.size() == 2)
	{
		///Remove the Top of the max heap and add it into the MinHeap.
		long long int top_element = maxHeap.top();
		maxHeap.pop();
		minHeap.push(top_element);

		///Now, Size of both heapS are Same, find the average of top of the two heaps.
		long long int sum = maxHeap.top() + minHeap.top();
		long long int average = sum / 2;
		median = average;
		return;
	}
	else if (minHeap.size() - maxHeap.size() == 2)
	{
		///Remove the Top of the min heap and add it into the MaxHeap.
		long long int top_element = minHeap.top();
		minHeap.pop();
		maxHeap.push(top_element);

		///Now, Size of both heapS are Same, find the average of top of the two heaps.
		long long int sum = maxHeap.top() + minHeap.top();
		long long int average = sum / 2;
		median = average;
		return;
	}
}
void median1(long long int d)
{
	if (maxHeap.empty())
	{
		maxHeap.push(d);
		median2();
		return;
	}
	else if (d > median)
	{
		///Add to minHeap
		minHeap.push(d);
		median2();
		return;
	}
	else if (d < median)
	{
		///Add to maxHeap
		maxHeap.push(d);
		median2();
		return;
	}
}
int main()
{
	long long int t;
	cin >> t;
	long long int i, j, d;
	for (i = 0; i < t; i++)
	{
		long long int n;
		cin >> n;
		for (j = 0; j < n; j++)
		{
			cin >> d;
			median1(d);
			cout << median << " ";
		}
		while (maxHeap.size() != 0)
		{
			maxHeap.pop();
		}
		while (minHeap.size() != 0)
		{
			minHeap.pop();
		}
		median = 0;
		cout << "\n";
	}
}
