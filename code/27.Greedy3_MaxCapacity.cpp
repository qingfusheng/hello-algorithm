#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 最大容量：贪心 */
int maxCapacity(vector<int> &ht) {
    // 初始化 i, j 分列数组两端
    int i = 0, j = ht.size() - 1;
    // 初始最大容量为 0
    int res = 0;
    // 循环贪心选择，直至两板相遇
    while (i < j) {
        // 更新最大容量
        int cap = min(ht[i], ht[j]) * (j - i);
        res = max(res, cap);
        // 向内移动短板
        if (ht[i] < ht[j]) {
            i++;
        } else {
            j--;
        }
    }
    return res;
}

int main(){

}