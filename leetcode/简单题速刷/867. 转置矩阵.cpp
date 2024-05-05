#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = matrix[i][j];
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> result = s.transpose(matrix);
    for (auto &row: result) {
        for (auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
1. 非方阵也可以转置
2. 二维数组直接初始化要比一个一个push_back快
*/