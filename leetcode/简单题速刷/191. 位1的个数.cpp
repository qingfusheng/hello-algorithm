#include<iostream>
#include<vector>
#include<string>
using namespace std;

int hammingWeight(int n) {
    int count = 0;
    while (n > 0) {
        if ((n & 1) == 1) {
            count++;
        }
        n >>= 1;

    }
    return count;
}

int main() {
    int result = hammingWeight(11);
    cout << result << endl;
    return 0;
}

/*
* // 官方题解，n& (n-1)可以消除1个设置位（1），所以可以用来计算1的个数
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n > 0){
            n = n & (n-1);
            ret ++;
        }
        return ret;
    }
};

*/