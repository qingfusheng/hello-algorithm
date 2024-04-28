// 题目名称：2617. 网格图中最少访问的格子数
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/minimum-number-of-visited-cells-in-a-grid/description
// 题目思路：Maybe DP or BFS (Copy  the solution from the website and paste it here.)  注意DP的剪枝，不剪枝会超时
// 题解：https://leetcode.cn/problems/minimum-number-of-visited-cells-in-a-grid/solutions/2693762/wang-ge-tu-zhong-zui-shao-fang-wen-de-ge-944f/comments/2261181
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || dp[i][j] == INT_MAX)
                    continue;
                int limx = min(grid[i][j] + i, m - 1);
                int limy = min(grid[i][j] + j, n - 1);
                int start;
                if (i > 1 && dp[i][j] == dp[i - 1][j]) // 剪枝
                    start = grid[i - 1][j] + i;
                else
                    start = i + 1;
                for (int x = start; x <= limx; x++)
                    dp[x][j] = min(dp[i][j] + 1, dp[x][j]);
                if (j > 1 && dp[i][j] == dp[i][j - 1]) // 剪枝
                    start = grid[i][j - 1] + j;
                else
                    start = j + 1;
                for (int y = start; y <= limy; y++)
                    dp[i][y] = min(dp[i][j] + 1, dp[i][y]);
            }
        }
        if (dp[m - 1][n - 1] == INT_MAX)
            return -1;
        else
            return dp[m - 1][n - 1];
    }
};

int main(){
    Solution so = Solution();
    vector<vector<int>> grid{{3,4,2,1},{4,2,3,1},{2,1,0,0},{2,4,0,0}};
    int result = so.minimumVisitedCells(grid);
    cout<<result<<endl;
    return 0;
}

/*
BFS+有序集合:https://leetcode.cn/problems/minimum-number-of-visited-cells-in-a-grid/solutions/2221898/bfsyou-xu-ji-he-cun-chu-mei-xing-yu-mei-1oxf0/
*/