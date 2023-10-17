// 还是K皇后
// 题目来源：洛谷
// 题目难度：普及/提高−
// 题目链接：https://www.luogu.com.cn/problem/P2105
// 备注：不加O2优化会TLE，加了O2优化就过了
#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

int main() {
    int n, m, K;
    cin >> n >> m >> K;
    // 行，列，主对角线，反对角线
    vector<bool> row(n, false);
    vector<bool> col(m, false);
    vector<bool> principle((m + n - 1), false);
    vector<bool> opposite((m + n - 1), false);
    for (int i = 0; i < K; i++) {
        int queenX, queenY;
        cin >> queenX >> queenY;
        queenX--, queenY--;
        row[queenX] = true;
        col[queenY] = true;
        principle[n - 1 - queenX + queenY] = true;
        opposite[queenX + queenY] = true;
    }

    int unattacked = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!(row[i] || col[j] || principle[n-1-i+j]||opposite[i+j]))
                unattacked += 1;
        }
    }

    cout << unattacked;
}
