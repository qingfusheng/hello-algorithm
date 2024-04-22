// 题目名称：1052. 爱生气的书店老板
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/grumpy-bookstore-owner/description/
// 题目思路: 滑动窗口
// 备注：
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
		int n = customers.size();
		int min_temp_cost = 0;
		for (int i = 0; i + minutes - 1 < n; i++) {
			int temp_cost = 0;
			for (int j = i; j < i + minutes; j++) {
				if (grumpy[j] == 1) {
					temp_cost += customers[j];
				}
			}

			min_temp_cost = max(min_temp_cost, temp_cost);
		}
		int total_cost = 0;
		for (int i = 0; i < n; i++) {
			if (grumpy[i] == 0) {
				total_cost += customers[i];
			}
		}
		return total_cost + min_temp_cost;
	}
};

int main() {
    Solution sol;
	vector<int> customers = {1};
	vector<int> grumpy = {0};
	int minutes = 3;
	cout << sol.maxSatisfied(customers, grumpy, minutes) << endl;
	return 0;
}

/*
// 滑动窗口，这样就不用每次都重新计算了
class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
		int n = customers.size();
		int total_cost = 0;
		for (int i = 0; i < n; i++) {
			if (grumpy[i] == 0) {
				total_cost += customers[i];
			}
		}
		
		int increase = 0;
		for (int i = 0; i < minutes; i++)
		{
			if (grumpy[i] == 1)
				increase += customers[i];
		}
		int max_increase = increase;
		for (int i = minutes; i < n; i++) {
			increase = increase - customers[i - minutes] * grumpy[i - minutes] + customers[i] * grumpy[i];
			max_increase = max(max_increase, increase);
		}
		return total_cost + max_increase;
	}
};

*/