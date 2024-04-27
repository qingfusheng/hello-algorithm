#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int temp = 1 - m; temp <= n - 1; temp++) {
            int i, j;
            if (temp < 0)
                i = 0 - temp, j = 0;
            else
                i = 0, j = temp;
            int val = matrix[i][j];
            while (++i < m && ++j < n) {
                if (matrix[i][j] != val)
                    return false;
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    cout << s.isToeplitzMatrix(matrix) << endl;
    return 0;
}

/*
官方题解：
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};

*/

/*
大佬题解（没有太懂到底是怎么讲jewels压缩进一个64位的整数的）：
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // 把 jewels 转换成字符集合 mask
        long long mask = 0;
        for (char c: jewels)
            mask |= 1LL << (c & 63);
        // 统计有多少 stones[i] 在集合 mask 中
        int ans = 0;
        for (char c: stones)
            ans += mask >> (c & 63) & 1;
        return ans;
    }
};

*/