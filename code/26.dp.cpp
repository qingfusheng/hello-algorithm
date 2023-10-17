#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void backtrack(vector<int>& choices, vector<int>& state, vector<vector<int>>& res, int target) {
	if (target == 0) {
		res.push_back(state);
		return;
	}
	for (int i = 0; i < choices.size(); i++) {
		int num = choices[i];
		// 剪枝
		if (target - num < 0)
			break;
		state.push_back(choices[i]);
		backtrack(choices, state, res, target - num);
		state.pop_back();
	}
}
// 使用回溯的方式
vector<vector<int>> StairClimbing1(int n) {
	vector<int> nums{1, 2};
	sort(nums.begin(), nums.end());  //每一步可以跨的楼梯数
	int target = n;
	vector<vector<int>> res;
	vector<int> state;
	backtrack(nums, state, res, target);
	return res;
}
int dfs1(int i) {
	if (i == 1 || i == 2)
		return i;
	int count = dfs1(i - 1) + dfs1(i - 2);
	return count;
}
int ClimbingStairsDFS1(int n) {
	// 指数阶的时间复杂度是由于“重叠子问题”导致的
	return dfs1(n);
}
/* 记忆化搜索 */
int dfs2(int i, vector<int>& mem) {
	// 已知 dp[1] 和 dp[2] ，返回之
	if (i == 1 || i == 2)
		return i;
	// 若存在记录 dp[i] ，则直接返回之
	if (mem[i] != -1)
		return mem[i];
	// dp[i] = dp[i-1] + dp[i-2]
	int count = dfs2(i - 1, mem) + dfs2(i - 2, mem);
	// 记录 dp[i]
	mem[i] = count;
	return count;
}

/* 爬楼梯：记忆化搜索 */
int climbingStairsDFSMem(int n) {
	// mem[i] 记录爬到第 i 阶的方案总数，-1 代表无记录
	vector<int> mem(n + 1, -1);
	return dfs2(n, mem);
}

/* 爬楼梯：动态规划 */
int climbingStairsDP(int n) {
	if (n == 1 || n == 2)
		return n;
	// 初始化 dp 表，用于存储子问题的解
	vector<int> dp(n + 1);
	// 初始状态：预设最小子问题的解
	dp[1] = 1;
	dp[2] = 2;
	// 状态转移：从较小子问题逐步求解较大子问题
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

/* 爬楼梯：空间优化后的动态规划 */
int climbingStairsDPComp(int n) {
	if (n == 1 || n == 2)
		return n;
	int a = 1, b = 2;
	for (int i = 3; i <= n; i++) {
		int tmp = b;
		b = a + b;
		a = tmp;
	}
	return b;
}


int main() {
	int num = 3;
	vector<vector<int>> result = StairClimbing1(num);
	for (auto& each_vector : result) {
		for (int each : each_vector)
			cout << each << ' ';
		cout << endl;
	}
	cout << "length:" << result.size();
}