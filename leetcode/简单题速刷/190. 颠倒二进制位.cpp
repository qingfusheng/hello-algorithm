#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<bool> bits(32, 0);
        for (int i = 0; i < 32; i++) {
            bits[i] = n & 1;
            n >>= 1;
        }
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= bits[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.reverseBits(43261596) << endl;
    return 0;
}

/*
* // 官方题解，并不需要将所有的位存下来
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; i < 32 && n > 0; ++i) {
            rev |= (n & 1) << (31 - i);
            n >>= 1;
        }
        return rev;
    }
};
*/

/*
* // 模仿官方题解自己写的
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32 && n > 0; i++) {
            res = res << 1;
            res = res | ((n >> i) & 1);
        }
        return res;
    }
};
*/