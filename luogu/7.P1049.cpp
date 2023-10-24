// 题目名称：P1049 [NOIP2001 普及组] 装箱问题
// 题目来源：洛谷
// 题目难度：普及-
// 题目链接：https://www.luogu.com.cn/problem/P1049
// 题目思路：动态规划，类似于01背包，需要注意的是，这里需要求的是剩余的最小体积，我们可以将每块的val设置成wgt，因此我们算最大价值的问题
// 就会转变成求最大可装入空间的问题，V-result即最小的剩余空间。
#include<iostream>
#include<vector>
using namespace std;
int ZhuangXiang(int V, int n, vector<int>wgt) {
	vector<int>dp(V + 1);
	for (int i = 1; i <= n; i++) {
		for (int c = V; c >= 1; c --) {
			if (wgt[i - 1] <= c) {
				dp[c] = max(dp[c], dp[c - wgt[i - 1]] + wgt[i - 1]);
			}
		}
	}
	return dp[V];
}
int main() {
	int V, n;
	cin >> V >> n;
	vector<int> wgt(n);
	for (int i = 0; i < n; i++)
		cin >> wgt[i];
	int result = ZhuangXiang(V, n, wgt);
	cout << V - result;
}