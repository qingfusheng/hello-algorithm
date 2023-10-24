// 题目名称：P1802 5 倍经验日
// 题目来源：洛谷
// 题目难度：普及-
// 题目链接：https://www.luogu.com.cn/problem/P1802
// 题目思路：动态规划，类似于01背包，但唯一不同的一点在于认输会有经验值（因此从c>=1到了c>=0
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
ll Battle(int x, vector<int> loss, vector<int> win, vector<int>use) {
	int n = loss.size();
	vector<ll> dp(x + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int c = x; c >= 0; c--) {
			if (use[i-1] > c) {
				dp[c] = dp[c] + loss[i - 1];
			}
			else {
				dp[c] = max(dp[c] + loss[i - 1], dp[c - use[i - 1]] + win[i - 1]);
			}
		}
	}
	
	return 5 * dp[x];
}
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> loss(n);
	vector<int> win(n);
	vector<int> use(n);
	for (int i = 0; i < n; i++)
		cin >> loss[i] >> win[i] >> use[i];
	ll result = Battle(x, loss, win, use);
	cout << result;

}