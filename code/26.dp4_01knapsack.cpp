// 01背包默认的条件是：每样物品只有一个（只能装一次
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int knapsackDP(vector<int>& wgt, vector<int>& val, int cap){
    // 状态转移方程：dp[i][c] = max(dp[i-1][c], dp[i-1][c-wgt[i-1]]+val[i-1]);
    int n = wgt.size();
    vector<vector<int>> dp(n+1, vector<int>(cap+1, 0));
    for(int i=1;i<=n;i++){
        for(int c=1;c<=cap;c++){
            if(wgt[i-1] > c){
                // 这是背包里面已经装不下i-1了
                dp[i][c] = dp[i-1][c];
            }else{
                dp[i][c] = max(dp[i-1][c], dp[i-1][c-wgt[i-1]]+val[i-1]);
            }
        }
    }
    return dp[n][cap];
}
/* 0-1 背包：空间优化后的动态规划 */
int knapsackDPComp(vector<int> &wgt, vector<int> &val, int cap) {
    /*横坐标为i，纵坐标为c
         0   1   2   3   4   5 
     0   0   0   0   0   0   0   
     1   0   5   5   5   5   5(05,1+0+0的策略)
     2   0   5  12  17  17  17(17,2+1+0的策略)
     3   0   5  12  17  21  27(27,3+2+1的策略)
     4   0   5  12  17  21  27(26,4+1+0的策略)
     5   0   5  12  17  21  27(24,5+0+0的策略)
    */
    int n = wgt.size();
    vector<int> dp(cap+1, 0);
    for(int i=1;i<=n;i++){
        for(int c=cap;c>=1;c--){
            if(wgt[i-1]<=c){
                // 倒序遍历c的原因是dp[c]会用到c之前的值
                dp[c] = max(dp[c], dp[c-wgt[i-1]]+val[i-1]);
            }
        }
    }
    return dp[cap];
    // dp[50] = max([wgt:10]+dp[40], [wgt:20]+dp[30])
}

int main(){
    int Cap, N;
    Cap = 5, N=5;
    vector<int> wgt{1,2,3,4,5};
    vector<int> val{5, 12, 15, 21, 24};
    // vector<vector<int>> wgt_val{{10,50},{20, 120},{30, 150},{40, 210},{50, 240}};
    int result1 = knapsackDP(wgt, val, Cap);
    int result2 = knapsackDPComp(wgt, val, Cap);
    cout<<"result1:"<<result1<<";result2:"<<result2<<endl;

}