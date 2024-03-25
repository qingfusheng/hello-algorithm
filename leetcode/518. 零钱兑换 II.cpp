// 题目名称：518. 零钱兑换 II
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/coin-change-ii/description/
// 题目思路：DP动态规划，找零钱问题，方案数
// 备注：完全背包问题，需要注意的是方案数的状态转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]
// 备注2：还有要注意的是，分清不同的DP题型，包括01背包、完全背包、多重背包、分组背包等，以及其不同的状态转移方程。

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	背包问题的大循环是wgt，小循环是容量cap，就相当于 针对于每一个coin尝试一次容量
	而现在这里是 找零钱问题，即一个 反向的背包问题，但是关键是需要将背包填满，
*/

/*
状态转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]
*/

int change1(int amount, vector<int>& coins) {
	// 二维Vector
	int n = coins.size();
	vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= amount; j++) {
			if (j >= coins[i - 1])
				dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	for (vector<int> each_vector : dp) {
		for (int each : each_vector)
			cout << each << ", ";
		cout << endl;
	}
	return dp[n][amount];
}

int change(int amount, vector<int>& coins) {
	// 压缩空间的解法
	int n = coins.size();
	vector<int> dp(amount + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= amount; j++)	// 问题，什么情况下这里需要倒序遍历，什么情况下是正序遍历 
			if (j >= coins[i])
				dp[j] += dp[j - coins[i]];
	return dp[amount];
}
int main() {
	int amount = 5;
	vector<int> coins = { 1,2,5 };
	int result = change(amount, coins);
	cout << result << endl;
	return 0;
}