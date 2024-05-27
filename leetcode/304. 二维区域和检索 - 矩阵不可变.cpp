// 题目名称：304. 二维区域和检索 - 矩阵不可变
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
// 题目思路：前缀和
// 备注：MyVec[i][j] = MyVec[i-1][j] + MyVec[i][j-1] - MyVec[i-1][j-1] + matrix[i-1][j-1]， 别忘了最后要加上matrix[i-1][j-1]
// 备注：

#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> MyVec;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        MyVec = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                MyVec[i][j] = MyVec[i-1][j] + MyVec[i][j-1] - MyVec[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return MyVec[row2 + 1][col2 + 1] - MyVec[row2 + 1][col1] - MyVec[row1][col2 + 1] + MyVec[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
int main(){
    vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
                                   {5, 6, 3, 2, 1},
                                   {1, 2, 0, 1, 5},
                                   {4, 1, 0, 1, 7},
                                   {1, 0, 3, 0, 5}};
    NumMatrix* obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2, 1, 4, 3) << endl;
    cout << obj->sumRegion(1, 1, 2, 2) << endl;
    cout << obj->sumRegion(1, 2, 2, 4) << endl;
    return 0;
}