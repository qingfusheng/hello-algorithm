#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n== 1) return true;
        if(n && n % 3 == 0){
            return isPowerOfThree(n / 3);
        }else{
            return false;
        }
    }
};

/*
// 取巧的做法，即找到int范围内最大的3的幂，然后用这个数对n取余，如果余数为0，则n是3的幂
class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n > 0 && 1162261467 % n == 0)
            return true;
        else
            return false;
    }
};
*/
