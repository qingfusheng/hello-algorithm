// 题目名称：322. 零钱兑换
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/coin-change/description/
// 题目思路：DP动态规划，经典问题
// 备注：dp初始值应该设置较大值，因为dp的状态转移方程有min
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // 申明dp数组，dp[i]表示凑成金额i所需的最少硬币数，初始指为amount+1（因为硬币数不可能超过amount）
    vector<int> dp(1e4 + 1, 1e4 + 1);
    dp[0] = 0;  // 金额为0时，所需硬币数为0
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
	int result = coinChange(coins, amount);
	cout << result;
	return 0;
}