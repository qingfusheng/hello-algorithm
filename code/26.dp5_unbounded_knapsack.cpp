// 完全背包和 0-1 背包问题非常相似，区别仅在于不限制物品的选择次数。
#include<iostream>
#include<vector>
using namespace std;
/* 完全背包：动态规划 */
int unboundedKnapsackDP(vector<int> &wgt, vector<int> &val, int cap) {
    int n = wgt.size();
    // 初始化 dp 表
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    // 状态转移
    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                // 若超过背包容量，则不选物品 i
                dp[i][c] = dp[i - 1][c];
            } else {
                // 不选和选物品 i 这两种方案的较大值
                dp[i][c] = max(dp[i - 1][c], dp[i][c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][cap];
}
/* 完全背包：空间优化后的动态规划 */
int unboundedKnapsackDPComp(vector<int> &wgt, vector<int> &val, int cap) {
    int n = wgt.size();
    // 初始化 dp 表
    vector<int> dp(cap + 1, 0);
    // 状态转移
    for (int i = 1; i <= n; i++) {
        // 01背包的cap是倒序遍历，完全背包是正序遍历（这两个的区别是什么
        for (int c = 1; c <= cap; c++) {
            if (wgt[i - 1] > c) {
                // 若超过背包容量，则不选物品 i
                dp[c] = dp[c];
            } else {
                // 不选和选物品 i 这两种方案的较大值
                dp[c] = max(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int c=cap;c>=1;c--){
            if(wgt[i-1]<=c){
                // 倒序遍历c的原因是dp[c]会用到c之前的值
                dp[c] = max(dp[c], dp[c-wgt[i-1]]+val[i-1]);
            }
        }
    }
    return dp[cap];
}

int main(){
     int Cap, N;
    Cap = 5, N=5;
    vector<int> wgt{1,2,3,4,5};
    vector<int> val{5, 12, 15, 21, 24};
    // vector<vector<int>> wgt_val{{10,50},{20, 120},{30, 150},{40, 210},{50, 240}};
    int result1 = unboundedKnapsackDP(wgt, val, Cap);
    int result2 = unboundedKnapsackDPComp(wgt, val, Cap);
    cout<<"result1:"<<result1<<";result2:"<<result2<<endl;

}