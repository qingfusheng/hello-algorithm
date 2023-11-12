// 题目名称：P2006 赵神牛的游戏
// 题目来源：洛谷
// 题目难度：入门
// 题目链接：https://www.luogu.com.cn/problem/P2006
// 题目思路：注意，这是一道简单题，且不能看两个样例就以为是个背包
// 备注：第一遍提交的时候RE了，显示浮点数错误，看了样例才发现value[i][0]可以为0
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int k, m, n;
	cin >> k >> m >> n;
	vector<vector<int>> value(m, vector<int>(2, 0));
	for (int i = 0; i < m; i++)
		cin >> value[i][0] >> value[i][1];
	vector<int> result_list;
	for (int i = 0; i < m; i++) {
        
		if (value[i][0] == 0 && value[i][1] == 0)
			continue;
		if (value[i][0] == 0 && value[i][1] > 0 || (k / value[i][0]) * value[i][1] >= n)
			result_list.push_back(i + 1);
	}
	if (result_list.size() == 0)
		result_list.push_back(-1);
	for (int i = 0; i < result_list.size(); i++)
		printf("%d ", result_list[i]);
}

/*
//备注：错误题解：将这道题当做是完全背包的问题，在法力值允许的范围内使用多个技能，最后看能不能打败BOSS。
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int SolveWithDP(vector<vector<int>> value, int cap, int mem) {
	int n = value.size();
	vector<int> dp(cap + 1, 0);
	for (int i = 1; i <= n; i++) {
		for (int c = 1; c <= cap; c++) {
			if (value[i - 1][0] > c) {
				dp[c] = dp[c];
			}
			else {
				dp[c] = max(dp[c], dp[c - value[i - 1][0]] + value[i - 1][1]);
			}
		}
	}
	return dp[cap] >= mem ? 1 : -1;
}
int main() {
	int k, m, n;
	cin >> k >> m >> n;
	vector<vector<int>> value(m, vector<int>(2, 0));
	for (int i = 0; i < m; i++)
		cin >> value[i][0] >> value[i][1];
	int result = SolveWithDP(value, k, n);
	cout << result;
}
*/