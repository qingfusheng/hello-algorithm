#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;  // 初始化掩码为 1

        // 寻找大于等于 n 的最小的全 1 掩码
        while (mask < n) {
            mask = (mask << 1) + 1;  // 将掩码左移一位并加 1
        }

        return n ^ mask; // 返回 n 和掩码的异或结果，即 n 的按位取反
    }
};

int main(){
    Solution s;
    cout << s.bitwiseComplement(5) << endl;
    return 0;
}

/*
1 ^ 1 = 0
0 ^ 1 = 1
（实现取反效果）
*/