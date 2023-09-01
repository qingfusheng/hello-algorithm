#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
	// less为大根堆，greater表示小跟堆
	priority_queue<int, vector<int>, less<int>> pqueue;
	pqueue.push(1);
	cout << pqueue.top() << "\n";
	pqueue.push(3);
	cout << pqueue.top() << "\n";
	pqueue.push(2);
	cout << pqueue.top() << "\n";
	pqueue.push(5);
	cout << pqueue.top() << "\n";
	pqueue.push(4);
	cout << pqueue.top() << "\n";
	pqueue.pop();
	cout << pqueue.top() << "\n";
	int size = pqueue.size();
	cout << "size:" << size << endl;
	vector<int> demo = { 1,3,2,5,4 };
	priority_queue<int, vector<int>, greater<int>> minHeap{demo.begin(), demo.end()};
	cout << minHeap.top() << endl;



}