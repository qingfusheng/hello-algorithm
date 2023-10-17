#include<iostream>
#include<vector>
using namespace std;
/* 回溯算法：N 皇后 */
void backtrack(int row, int n, vector<vector<bool>>& state, vector<vector<vector<bool>>>& res, vector<bool>& cols,
    vector<bool>& diags1, vector<bool>& diags2) {
    // 当放置完所有行时，记录解
    if (row == n) {
        res.push_back(state);
        return;
    }
    // 遍历所有列
    for (int col = 0; col < n; col++) {
        // 计算该格子对应的主对角线和副对角线
        int diag1 = row - col + n - 1;
        int diag2 = row + col;
        // 剪枝：不允许该格子所在列、主对角线、副对角线存在皇后
        if (!cols[col] && !diags1[diag1] && !diags2[diag2]) {
            // 尝试：将皇后放置在该格子
            state[row][col] = true;
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            // 放置下一行
            backtrack(row + 1, n, state, res, cols, diags1, diags2);
            // 回退：将该格子恢复为空位
            state[row][col] = false;
            cols[col] = diags1[diag1] = diags2[diag2] = false;
        }
    }
}

/* 求解 N 皇后 */
vector<vector<vector<bool>>> nQueens(int n) {
    // 初始化 n*n 大小的棋盘，其中 1 代表皇后，0 代表空位
    vector<vector<bool>> state(n, vector<bool>(n, false));
    vector<bool> cols(n, false);           // 记录列是否有皇后
    vector<bool> diags1(2 * n - 1, false); // 记录主对角线是否有皇后
    vector<bool> diags2(2 * n - 1, false); // 记录副对角线是否有皇后
    vector<vector<vector<bool>>> res;
    backtrack(0, n, state, res, cols, diags1, diags2);

    return res;
}
int main() {
    int num = 13;
    vector<vector<vector<bool>>> result = nQueens(num);
    for (vector<vector<bool>> each_vector_vector : result) {
        for (vector<bool> each_vector : each_vector_vector) {
            for (bool each : each_vector) {
                cout << each << " ";
            }
            cout << endl;
        }
        cout << "------------------------------------\n";
    }
}
/*
Input: 6
Output:
0 1 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 1
1 0 0 0 0 0
0 0 1 0 0 0
0 0 0 0 1 0
------------------------------------
0 0 1 0 0 0
0 0 0 0 0 1
0 1 0 0 0 0
0 0 0 0 1 0
1 0 0 0 0 0
0 0 0 1 0 0
------------------------------------
0 0 0 1 0 0
1 0 0 0 0 0
0 0 0 0 1 0
0 1 0 0 0 0
0 0 0 0 0 1
0 0 1 0 0 0
------------------------------------
0 0 0 0 1 0
0 0 1 0 0 0
1 0 0 0 0 0
0 0 0 0 0 1
0 0 0 1 0 0
0 1 0 0 0 0
------------------------------------
*/