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
    int n = wgt.size();
    // 为什么这里从正序到逆序就可以将dp从二维缩减到一维
    vector<int> dp(cap + 1, 0);
    for(int i=1; i<=n; i++){
        for(int c=cap;c>=1;c--){
            cout<<"i:"<<i<<",c:"<<c<<endl;
            if(wgt[i-1] > c){
                cout<<"背包容量小了装不下了:"<<wgt[i-1]<<endl;
                dp[c] = dp[c];
            }else{
                cout<<"选择不装的价值:"<<dp[c]<<",VS选择装的价值:"<<dp[c-wgt[i-1]]+val[i-1];
                dp[c] = max(dp[c], dp[c-wgt[i-1]]+val[i-1]);
                cout<<",结果价值为："<<dp[c]<<endl;
            }
        }
        for(int c=cap;c>=0;c--)
            cout<<c<<":"<<dp[c]<<" ,";
        cout<<endl;
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