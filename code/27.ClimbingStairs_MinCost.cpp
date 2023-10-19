// 爬楼梯(最小代价)
// return: 最小代价（而不是所有方案数量）
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 爬楼梯最小代价：动态规划 */

// 使用dp数组
int minCostClimbingStairsDP(vector<int> &cost) {
    // cost : [0, 1, 2] (其中还包括了第0个台阶，指当前状态，还没跨出的时候cost为0)
    int n = cost.size() - 1;
    if(n == 1 || n == 2)
        return cost[n];
    vector<int> dp(n+1);
    dp[1] = cost[1];
    dp[2] = cost[2];
    for(int i=3;i<=n;i++)
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    return dp[n];
}
// 使用变量替代数组，减小了空间占用
int minCostClimbingStairsDPcomp(vector<int>& cost){
    int n = cost.size() - 1;
    if(n==1 || n==2)
        return cost[n];
    int a=cost[1], b = cost[2];
    for(int i=3;i<=n;i++){
        int temp = b;
        b = min(a,b)+cost[i];
        a = temp;
    }
    return b;
}


int main(){
    vector<int> costs{0, 1,10,1};
    int reuslt1 = minCostClimbingStairsDP(costs);
    int result = minCostClimbingStairsDPcomp(costs);
    cout<<"result:"<<result;
}