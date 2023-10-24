// 题目名称：疯狂的采药
// 题目来源：洛谷
// 题目难度：普及-
// 题目链接：https://www.luogu.com.cn/problem/P1616
// 题目思路：动态规划，完全背包（可重复选择
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long Cy(int cap, int n, vector<int>&wgt, vector<int>&val) {
	vector<long long int> dp(cap + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int c = 1; c <= cap; c++) {
			if (wgt[i - 1] <= c) {
				dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
			}
		}
	}
	return dp[cap];
}
int main() {
	int t, m;
	cin >> t >> m;
	vector<int> wgt(m);
	vector<int> val(m);
	for (int i = 0; i < m; i++)
		cin >> wgt[i] >> val[i];
	long long result = Cy(t, m, wgt, val);
	cout << result;
}