// https://leetcode.cn/problems/minimum-skips-to-arrive-at-meeting-on-time
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        if (accumulate(dist.begin(), dist.end(), 0) > (long long) speed * hoursBefore) {
            return -1;
        }
        int n = dist.size();
        vector<vector<int>> memo(n, vector<int>(n, -1)); // -1 表示没有计算过
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (j < 0) { // 递归边界
                return 0;
            }
            auto& res = memo[i][j]; // 注意这里是引用
            if (res != -1) { // 之前计算过
                return res;
            }
            res = (dfs(i, j - 1) + dist[j] + speed - 1) / speed * speed;
            if (i) res = min(res, dfs(i - 1, j - 1) + dist[j]);
            return res;
        };
        for (int i = 0; ; i++) {
            if (dfs(i, n - 2) + dist[n - 1] <= (long long) speed * hoursBefore) {
                return i;
            }
        }
    }
};
// 灵茶山艾府

int main(){
    Solution s;
    vector<int> dist = {1,3,2};
    int speed = 4;
    int hoursBefore = 2;
    cout << s.minSkips(dist, speed, hoursBefore) << endl;
    return 0;
}