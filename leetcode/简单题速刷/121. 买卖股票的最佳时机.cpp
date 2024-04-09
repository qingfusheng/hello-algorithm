#include <bits/stdc++.h>
using namespace std;

// DP的优化内存版本，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            maxPro = max(maxPro, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return maxPro;
    }
};


int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
/*
 * // DP解法,时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i] = max(dp[i-1], prices[i] - min(prices[0:i-1]))
        vector<int> dp(prices.size(), 0);
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = max(dp[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return dp[prices.size() - 1];

    }
};
*/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 暴力双循环会过200/212个测试点[超时]
        int max_pre = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            for(int j = i + 1;j < prices.size();j++){
                max_pre = max(max_pre, prices[j] - prices[i]);
            }
        }
        return max_pre;
    }
};
*/