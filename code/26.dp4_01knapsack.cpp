#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int knapsackDP(vector<int>& wgt, vector<int>& val, int cap){
    // 状态转移方程：dp[i][c] = max(dp[i-1][c], dp[i-1][c-wgt[i-1]]+val[i-1]);
    int n = wgt.size();
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i=1;i<=n;i++){
        for(int c=1; c<=cap;c++){
            if(wgt[i-1] > c)
                dp[i][c] = dp[i-1][c];
            else
                dp[i][c] = max(dp[i-1][c], dp[i-1][c-wgt[i-1]]+val[i-1]);
        }
    }
    return dp[n][cap];
}
/* 0-1 背包：空间优化后的动态规划 */
int knapsackDPComp(vector<int> &wgt, vector<int> &val, int cap) {
    int n = wgt.size();
    // 初始化 dp 表
    vector<int> dp(cap + 1, 0);
    // 状态转移
    for (int i = 1; i <= n; i++) {
        // 倒序遍历
        for (int c = cap; c >= 1; c--) {
            if (wgt[i - 1] <= c) {
                // 不选和选物品 i 这两种方案的较大值
                dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[cap];
}

int main(){
    int Cap, N;
    Cap = 50, N=5;
    vector<int> wgt{10,20,30,40,50};
    vector<int> val{50, 120, 150, 210, 240};
    // vector<vector<int>> wgt_val{{10,50},{20, 120},{30, 150},{40, 210},{50, 240}};
    int result1 = knapsackDP(wgt, val, Cap);
    int result2 = knapsackDPComp(wgt, val, Cap);
    cout<<"result1:"<<result1<<";result2:"<<result2<<endl;

}