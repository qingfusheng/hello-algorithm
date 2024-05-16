// 题目名称：1953. 你可以工作的最大周数
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/description/
// 题目思路：贪心，当最大任务数大于其他任务数之和时，最大周数为其他任务数之和的两倍加一，否则为所有任务数之和

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long largest = *max_element(milestones.begin(), milestones.end());
        long long sum = accumulate(milestones.begin(), milestones.end(), (long long)0);
        long long rest = sum - largest;
        return largest > rest + 1 ? rest * 2 + 1: sum;
    }
};

int main(){
    Solution sol;
    vector<int> milestones = {1,2,3};
    cout << sol.numberOfWeeks(milestones) << endl;
    return 0;
}