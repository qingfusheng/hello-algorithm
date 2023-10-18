/*
	# 上楼梯问题
	很明显，这道题可以用三种方法来解答，回溯，深搜和动规。
	回溯实质上是对所有可选择项的遍历，时间复杂性很高，当n较大时，执行时间会呈现爆炸式增长，所以TLE的可能性很高。
	而与之相对的，动态规划DP常用来得出某些情况的特征，而不能得出详细的子集（可行的方案数√，所有的方案子集×）
	结果证明：回溯的运行慢的离谱，当num=50的时候，各种算法的时间：11932667, 577880, 0, 0, 0(微秒)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include <chrono>
using namespace std;
// 回溯（跟子集那道题很相似
void backtrack(vector<int>& choices, vector<int>& state, vector<int>&res, int target) {
	if (target == 0) {
		res[0]+=1;
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
int ClimbingStairs1(int n) {
	vector<int> nums{1, 2};
	// sort(nums.begin(), nums.end());  //每一步可以跨的楼梯数（可以没有，毕竟可以可以手动排序
	int target = n;
	vector<int> res{0};
	vector<int> state;
	backtrack(nums, state, res, target);
	return res[0];
}
/* 深搜1：暴力搜索（类似与回溯，但写法更简单） */
int dfs1(int i) {
	if (i == 1 || i == 2)
		return i;
	int count = dfs1(i - 1) + dfs1(i - 2);
	return count;
}
int ClimbingStairsDFS(int n) {
	// 指数阶的时间复杂度是由于“重叠子问题”导致的，就比如dfs(10)要算dfs(9)和dfs(8)，而dfs(9)又要将dfs(8)算一遍
	return dfs1(n);
}
/* 深搜2：记忆化搜索（对暴力搜索的优化） */
// 相比于上面，记忆化搜索对搜索过程进行剪枝，已经计算过的不需要再计算第二次，但会增加空间复杂度（需要额外的空间来存储dfs(k-1),k∈[1,n-1]
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
int climbingStairsDFSMem(int n) {
	// mem[i] 记录爬到第 i 阶的方案总数，-1 代表无记录
	vector<int> mem(n + 1, -1);
	return dfs2(n, mem);
}

/* 动规1：动态规划（从较小子问题逐步求解较大子问题） */
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

/* 动规2：动态规划（空间优化后的动态规划）*/
int climbingStairsDPComp(int n) {
	if (n == 1 || n == 2)
		return n;
	int a = 1, b = 2;
	for (int i = 3; i <= n; i++) {
		// dp[i] = dp[i-1] + dp[i-2]
		// x: dp[i-2], y: dp[i-1], z: dp[i]
		// (x, y) -> (y, z)
		// (a, b) -> (b, a+b)
		int tmp = b;
		b = a + b;
		a = tmp;
	}
	return b;
}


int main() {
	int num = 40;
	std::chrono::system_clock::time_point start, end;
	start = std::chrono::system_clock::now();
	int result1 = ClimbingStairs1(num);
	end = std::chrono::system_clock::now();
	cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<endl;

	start = std::chrono::system_clock::now();
	int result2 = ClimbingStairsDFS(num);
	end = std::chrono::system_clock::now();
	cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<endl;

	start = std::chrono::system_clock::now();
	int result3 = climbingStairsDFSMem(num);
	end = std::chrono::system_clock::now();
	cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<endl;

	start = std::chrono::system_clock::now();
	int result4 = climbingStairsDP(num);
	end = std::chrono::system_clock::now();
	cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<endl;

	start = std::chrono::system_clock::now();
	int result5 = climbingStairsDPComp(num);
	end = std::chrono::system_clock::now();
	cout<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count()<<endl;

	cout<<result1<<", "<<result2<<", "<<result3<<", "<<result4<<", "<<result5;
}







