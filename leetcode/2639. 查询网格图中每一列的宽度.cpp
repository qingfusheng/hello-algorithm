// 题目名称：2639. 查询网格图中每一列的宽度
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/find-the-width-of-columns-of-a-grid/description
// 题目思路：模拟，注意负数和0即可
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result;
        for(int i=0;i<n;i++){
            int max_length = 0;
            for(int j = 0; j < m; j++){
                int length = 0;
                int temp = grid[j][i];
                if(temp < 0){
                    temp = 0 - temp;
                    length += 1;
                }
                if(temp == 0)length += 1;
                while(temp > 0){
                    length ++;
                    temp /= 10;
                }
                max_length = max(max_length, length);
            }
            result.push_back(max_length);
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = s.findColumnWidth(grid);
    for(auto i:result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}