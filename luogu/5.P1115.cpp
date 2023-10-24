// 题目名称：P1115 最大子段和
// 题目来源：洛谷
// 题目难度：普及-
// 题目链接：https://www.luogu.com.cn/problem/P1115
// 题目思路：动态规划，状态转移方程：dp[i] = max(nums[i-1], dp[i-1]+nums[i-1]);
#include<iostream>
#include<vector>
using namespace std;
int SubSegSum(int n, vector<int> nums) {
	// 将n维空间压缩到一维，仅使用两个变量来标志状态变化
	//vector<int> dp(n + 1, 0);
	int a = 0, b = 0;
	int max_sum = nums[0];
	for (int i = 1; i <= n; i++) {
		b = max(nums[i - 1], a + nums[i - 1]);
		//dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
		a = b;
		if (max_sum < b)
			max_sum = b;
	}
	return max_sum;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int result = SubSegSum(n, a);
	cout<< result;
}