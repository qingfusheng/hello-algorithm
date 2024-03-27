// 题目名称：1997. 访问完所有房间的第一天
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/first-day-where-you-have-been-in-all-the-rooms/description/
// 题目思路：DP，状态转移方程dp[i] = (2 + dp[i - 1] + dp[i - 1] - dp[nextVisit[i - 1]] + 1000000007) % 1000000007
// 备注：AI秒的，被AI秒了，以后慢慢参悟

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstDayBeenInAllRooms(vector<int>& nextVisit) {
    int n = nextVisit.size();
    vector<long long> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        dp[i] = (2 + dp[i - 1] + dp[i - 1] - dp[nextVisit[i - 1]] + 1000000007) % 1000000007;
    }
    return dp[n - 1];
}

int main() {
    vector<int> nextVisit{ 0, 1,2,0};
    int result = firstDayBeenInAllRooms(nextVisit);
    cout << result << endl;
}