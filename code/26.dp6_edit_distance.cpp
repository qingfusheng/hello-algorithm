#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// 在编辑距离问题中，s串可以认为1-n的药草，而t可以认定为背包，所以可以将
// 问题抽象为将s串放入t串的问题，而编辑操作可以认定为i要不要装入j的过程
int EditDistanceDP(string& s, string& t) {
	// 从source到target的编辑距离
	int n = s.length(), m = t.length();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
		dp[i][0] = i;
	for (int j = 1; j <= m; j++)
		dp[0][j] = j;
	// 问：为什么要对边界值进行赋值
	/*
	0 1 2 3 4 5 6 7 8
	1 0 0 0 0 0 0 0 0
	2 0 0 0 0 0 0 0 0
	3 0 0 0 0 0 0 0 0
	4 0 0 0 0 0 0 0 0
	5 0 0 0 0 0 0 0 0
	6 0 0 0 0 0 0 0 0
	*/
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				/*
				dp[i][j] = dp[i][j-1] + 1，插入
				dp[i][j] = dp[i-1][j] + 1，删除
				dp[i][j] = dp[i-1][j-1] + 1， 替换
				*/
				dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			printf("%2d ", dp[i][j]);
		cout << endl;
	}
	return dp[n][m];
}
int EditDistanceDPComp(string& s, string& t) {
	int n = s.length(), m = t.length();
	vector<int>dp(m + 1, 0);
	int leftup; // leftup代表的是dp[i-1][j-1]
	for (int j = 1; j <= m; j++)
		dp[j] = j;
	/*
	0 1 2 3 4 5 6 7 8
	*/
	// 因为在状态转移的时候我们只需要考虑dp[i][j], dp[i-1][j], dp[i][j-1], dp[i-1][j-1]，
	// 一维数组可以表示dp[i][j], dp[i-1][j], dp[i][j-1],而dp[i-1][j-1]需要额外变量来存储
	for (int i = 1; i <= n; i++) {
		// dp[i][~]
		leftup = dp[0];  // 初始状态下j=1，因此赋值为dp[0]
		dp[0] = i;  // 同for(i:1->n)dp[i][0]=i
		for (int j = 1; j <= m; j++) {
			// leftup -> dp[i-1][j-1]
			// dp[j] -> dp[i][j]
			int temp = dp[j];  // dp[i][j]
			if (s[i - 1] == t[j - 1])
				dp[j] = leftup;
			else
				dp[j] = min(min(dp[j], dp[j - 1]), leftup) + 1;
			leftup = temp;
		}
	}
	for (int i = 0; i <= m; i++)
		printf("%2d ", dp[i]);
	cout << endl;
	return dp[m];

}
int main() {
	string a = "hello world";
	string b = "helaotorlcd";
	//int result = EditDistanceDP(a, b);
	int result = EditDistanceDPComp(a, b);
	cout << "result:" << result << endl;
}