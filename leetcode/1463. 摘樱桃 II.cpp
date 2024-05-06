// 题目名称：1463. 摘樱桃 II
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/cherry-pickup-ii/description/
// 题目思路：动态规划，状态压缩

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> f(n, vector<int>(n, -1)), g(n, vector<int>(n, -1));
        f[0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int best = -1;
                    for (int dj1 = j1 - 1; dj1 <= j1 + 1; ++dj1) {
                        for (int dj2 = j2 - 1; dj2 <= j2 + 1; ++dj2) {
                            if (dj1 >= 0 && dj1 < n && dj2 >= 0 && dj2 < n && f[dj1][dj2] != -1) {
                                best = max(best, f[dj1][dj2] + (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]));
                            }
                        }
                    }
                    g[j1][j2] = best;
                }
            }
            swap(f, g);
        }

        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1) {
            for (int j2 = 0; j2 < n; ++j2) {
                ans = max(ans, f[j1][j2]);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    cout << s.cherryPickup(grid) << endl;
}