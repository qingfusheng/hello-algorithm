// 题目名称：2952. 需要添加的硬币的最小数量
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/minimum-number-of-coins-to-be-added/description
// 题目思路：贪心算法
// 备注：// 最初的时候我将它认为是一道填1-2-4-8-16-···然后完全背包的问题，再加一个visited数组，emmm，反正就是很复杂化，导致到背包那里就不想写了，然后看题解才发现这是一道贪心？该好好复习归纳法了
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimumAddedCoins(vector<int>& coins, int target) {
	sort(coins.begin(), coins.end());
	int res = 0, n = coins.size(), s = 1, index = 0;
	while (s <= target) {
		// 原来 index < n && coins[index] <= s 与 coins[index] <= s && index < n的作用不一样？
		if (index < n && coins[index] <= s) {
			s += coins[index++];
		}
		else {
			s *= 2;
			res++;
		}
	}
	return res;
}

int main() {
	vector<int> coins = { 1,4,10 };
	int target = 19;
	cout << minimumAddedCoins(coins, target) << endl;
	return 0;
}

