#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2)
            return n;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++)
            dp[i] = dp[i-1]+dp[i-2];
        return dp[n];
    }
    int climbStairs2(int n) {
        if(n==1||n==2)
            return n;
        return climbStairs2(n-1)+climbStairs2(n-2);
    }
};
int main(){
    Solution s;
    cout << s.climbStairs(3) << endl;
    return 0;
}

/*
 * dp可以，用递归会超时
*/