// 题目名称：P1164 小A点菜
// 题目来源：洛谷
// 题目难度：普及-
// 题目链接：https://www.luogu.com.cn/problem/P1164
// 题目思路：动态规划，类似于01背包，这是某个题解，实质上我并没有看懂，首先是刚好花完的条件（状态方程），以及dp的初始状态（dp[0]
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> wgt(N);
	for (int i = 0; i < N; i++)
		cin >> wgt[i];

	
	vector<int> dp(M + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int c = M; c >= wgt[i-1]; c--) {
			if (wgt[i - 1] <= c) {
				dp[c] += dp[c - wgt[i - 1]];
			}
		}
	}
	cout << dp[M];
}