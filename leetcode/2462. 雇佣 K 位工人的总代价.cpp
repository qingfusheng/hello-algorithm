// 题目名称：2462. 雇佣 K 位工人的总代价
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/total-cost-to-hire-k-workers/description
// 题目思路：题解
// https://leetcode.cn/problems/total-cost-to-hire-k-workers/solutions/1951938/liang-ge-zui-xiao-dui-mo-ni-by-endlessch-nagm

#include<iostream>
#include<vector>
#include<numeric>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        if (candidates * 2 + k > n) {
            ranges::nth_element(costs, costs.begin() + k);
            return accumulate(costs.begin(), costs.begin() + k, 0LL);
        }

        long long ans = 0;
        priority_queue<int, vector<int>, greater<>> pre, suf;
        for (int i = 0; i < candidates; i++) {
            pre.push(costs[i]);
            suf.push(costs[n - 1 - i]);
        }
        int i = candidates, j = n - 1 - candidates;
        while (k--) {
            if (pre.top() <= suf.top()) {
                ans += pre.top();
                pre.pop();
                if (i <= j) {
                    pre.push(costs[i++]);
                }
            } else {
                ans += suf.top();
                suf.pop();
                if (i <= j) {
                    suf.push(costs[j--]);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> costs = {1, 3, 2, 5, 4};
    int k = 3, candidates = 1;
    cout << s.totalCost(costs, k, candidates) << endl;
    return 0;
}