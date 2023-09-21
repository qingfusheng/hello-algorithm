#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<chrono>
using namespace std;
void view_vector(vector<int> nums) {
	for(vector<int>::iterator it = nums.begin(); it < nums.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

vector<int> getTopK_method1(vector<int> nums, int k) {
	vector<int> result(k);
	vector<int> result_index;
	for (int i = 0; i < k; i++) {
		int max_index = 0;
		for (int j = 0; j < nums.size();j++) {
			int skip_flag = false;
			for (vector<int>::iterator it = result_index.begin(); it < result_index.end(); it++) {
				if (*it == j) {
					skip_flag = true;
					break;
				}
			}
			if (skip_flag)
				continue;
			if (nums[j] > nums[max_index]) {
				max_index = j;
			}
		}
		result_index.push_back(max_index);

	}
	for (int i = 0; i < k; i++)
		result[i] = nums[result_index[i]];
	return result;
}
vector<int> getTopK_method2(vector<int> nums, int k) {
	//vector<int> result;
	sort(nums.begin(), nums.end());
	reverse(nums.begin(), nums.end());
	vector<int> result(nums.begin(), nums.begin() + k);
	return result;
}
// 数据量越大，运行差距效率就会越大，优先队列表现稳定，且优先队列的主要在建堆上耗时较多，在查询过程耗时少
vector<int> getTopK_method3(vector<int> nums, int k) {
	
	priority_queue<int, vector<int>, greater<int>> pqueue;
	for (int i = 0; i < nums.size(); i++) {
		if (pqueue.size() < k) {
			pqueue.push(nums[i]);
		}
		else {
			if (nums[i] < pqueue.top())
				continue;
			else {
				pqueue.pop();
				pqueue.push(nums[i]);
			}
		}
	}
	vector<int>result;
	while (!pqueue.empty()) {
		result.push_back(pqueue.top());
		pqueue.pop();
	}
	return result;
}
int main() {
	vector<int> nums;
	for (int i = 0; i < 10000; i++)
		nums.push_back(i);
	random_shuffle(nums.begin(), nums.end());
	auto begin_time = chrono::steady_clock::now();
	//vector<int> result = getTopK_method1(nums, 10);
	//vector<int> result = getTopK_method2(nums, 10);
	vector<int> result = getTopK_method3(nums, 10);
	auto end_time = chrono::steady_clock::now();
	auto time_span = chrono::duration_cast<chrono::microseconds>(end_time - begin_time);
	cout << time_span.count() << endl;
	view_vector(result);
}