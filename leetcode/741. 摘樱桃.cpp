// 题目名称：741. 摘樱桃
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/cherry-pickup/description/
// 题目思路：题解：https://leetcode.cn/problems/cherry-pickup/solutions/97703/dong-tai-gui-hua-xiang-xi-jie-xi-tu-jie-by-newhar

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size(), dp[N+1][N+1];
        memset(dp, 0x80, sizeof(dp)); //-2139062144, 作用相当于 INT_MIN
        dp[N-1][N-1] = grid[N-1][N-1]; // 初始边界条件
        for(int sum = 2*N - 3; sum >= 0; --sum)
        for(int i1 = max(0, sum - N + 1); i1 <= min(N-1,sum); ++i1)
        for(int i2 = i1; i2 <= min(N-1,sum); ++i2)
        {
            int j1 = sum - i1, j2 = sum - i2;
            if(grid[i1][j1] == -1 || grid[i2][j2] == -1) 
                dp[i1][i2] = INT_MIN;
            else
                dp[i1][i2] = grid[i1][j1] + (i1 != i2 || j1 != j2)*grid[i2][j2] + max(
                    max(dp[i1][i2+1], dp[i1+1][i2]), 
                    max(dp[i1+1][i2+1], dp[i1][i2])
                );
        }
        return max(0, dp[0][0]);     
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0,1,-1},{1,0,-1},{1,1,1}};
    cout << s.cherryPickup(grid) << endl;
    return 0;
}