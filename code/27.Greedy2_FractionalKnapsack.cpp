/*
Type: 分数背包
Question:给定n个物品，第i个物品的重量为wgt[i]、价值为val[i]，和一个容量为cap的背包。每个物品只能选择一次，但可以选择物品的一部分，价值根据选择的重量比例计算，问在不超过背包容量下背包中物品的最大价值。
Method: Greedy Algorithm
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item{
    int wgt;
    int val;
    Item(int t_wgt, int t_val): wgt(t_wgt), val(t_val){}
};
double FractionalKnapsack(vector<int>& wgt, vector<int>& val, int cap){
    vector<Item> items;
    for(int i=0;i<wgt.size();i++){
        items.push_back(Item(wgt[i], val[i]));
    }
    sort(items.begin(), items.end(), [](Item &a, Item &b) { return (double)a.val / a.wgt > (double)b.val / b.wgt; });
    // 循环贪心选择
    double res = 0;
    for (auto &item : items) {
        if (item.wgt <= cap) {
            // 若剩余容量充足，则将当前物品整个装进背包
            res += item.val;
            cap -= item.wgt;
        } else {
            // 若剩余容量不足，则将当前物品的一部分装进背包
            res += (double)item.val / item.wgt * cap;
            // 已无剩余容量，因此跳出循环
            break;
        }
    }
    return res;
}
int main(){
    vector<int> wgt{10, 20, 30, 40, 50};
    vector<int> val{50, 120, 150, 210, 240};
    double res = FractionalSnapsack(wgt, val, 50);
}