/*
# 贪心算法

## 贪心算法特性
- 贪心选择性质：只有当局部最优选择始终可以导致全局最优解时，贪心算法才能保证得到最优解。
- 最优子结构：原问题的最优解包含子问题的最优解。

## 贪心结题步骤
- 问题分析：梳理与理解问题特性，包括状态定义、优化目标和约束条件等。这一步在回溯和动态规划中都有涉及。
- 确定贪心策略：确定如何在每一步中做出贪心选择。这个策略能够在每一步减小问题的规模，并最终能解决整个问题。
- 正确性证明：通常需要证明问题具有贪心选择性质和最优子结构。这个步骤可能需要使用到数学证明，例如归纳法或反证法等。

## 贪心典型例题
- 硬币找零问题
- 区间调度问题
- 分数背包问题
- 股票买卖问题
- 霍夫曼编码
- Dijkstra算法（最短路径算法）
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void CoinChangeGreedy(vector<int>& coins, int amt){
    sort(coins.begin(), coins.end());
    int i = coins.size() - 1;  // the index of coins
    int count = 0;
    while(amt > 0){
        while(i > 0 && coins[i] > amt){
            i--;
        }
        amt -= coins[i];
        count++;
    }
    if (amt == 0)
        cout<<"count:"<<count<<endl;
    else
        cout<<"No Solution"<<endl;
    // return amt == 0 ? count : -1;
}
int main(){
    /*-------------------------------------Begin---------------------------------------*/
    // Appearly, It is not a correct solution. The Answer is 2 {20,20}, not 3 {30, 5, 5}。
    // Actually, DP is the best solution.
    vector<int> coins{5,20,30};
    CoinChangeGreedy(coins, 40);
    // 对于零钱兑换问题，贪心算法无法保证找到全局最优解
    /*-------------------------------------End-----------------------------------------*/


}