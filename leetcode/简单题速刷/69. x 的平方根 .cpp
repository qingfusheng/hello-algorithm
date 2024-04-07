#include<iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = 46340;
        int ans = -1;
        while (left <= right) {
            // int mid = (left + right) / 2;
            int mid = left + (right-left)/2;
            if (x >= mid * mid) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};


int main(){
    Solution s;
    cout << s.mySqrt(8) << endl;
    return 0;
}

/*
// 注意浮点数的精度问题
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};

*/