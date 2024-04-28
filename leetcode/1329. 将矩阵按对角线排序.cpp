// 题目名称：1329. 将矩阵按对角线排序
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/sort-the-matrix-diagonally/description
// 题目思路：将每一个对角线元素放入一个数组中，然后对数组进行排序，再将数组中的元素放回到对角线中
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> temp;
        for(int i = 1 - m; i < n; i++){
            int x = i < 0 ? 0 - i : 0;
            int y = i < 0 ? 0 : i;
            while(x < m && y < n){
                temp.push_back(mat[x++][y++]);
            }
            sort(temp.begin(), temp.end());
            int index = temp.size() - 1;
            while(index >= 0){
                mat[--x][--y] = temp[index--];
            }
            temp.clear();
        }
        return mat;
    }
};
int main(){
    Solution s;
    vector<vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    vector<vector<int>> res = s.diagonalSort(mat);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
    效率：73.45%和87.61%
*/