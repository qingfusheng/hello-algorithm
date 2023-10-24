// 题目名称：[NOIP2005 普及组] 采药
// 题目来源：洛谷
// 题目难度：普及-
// 题目链接：https://www.luogu.com.cn/problem/P1048
// 题目思路：动态规划，01背包（不重复选择
#include<iostream>
#include<vector>
using namespace std;
int T, M;
// F[i]为是否采第i束草药的最优价值
// C[i],V[i](采药时间，采药价值)
int F[1005], C[105], V[105];;
void cy() {
	for(int i=1;i<=M;i++)
		for (int j = T; j >= 0; j--)
			if(j >= C[i])
				F[j] = max(F[j], F[j - C[i]] + V[i]);
}
int main(){
    cin >> T >> M;
	for (int i = 1; i <= M; i++)
		cin >> C[i] >> V[i];
	cy();
	cout << F[T];
}