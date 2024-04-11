#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)return true;
        if(n && n %4 == 0){
            return isPowerOfFour(n/4);
        }else
            return false;
    }
};

/*
// mask=(10101010101010101010101010101010) ,n与mask进行按位与运算
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    }
};

*/