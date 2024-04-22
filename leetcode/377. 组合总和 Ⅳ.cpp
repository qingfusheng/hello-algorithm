// 题目名称：377. 组合总和 Ⅳ
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/combination-sum-iv/description/
// 题目思路：因为不需要组合，所以可以使用动态规划，而回溯很明显会超时
// 备注：状态在转移方程为 dp[i] = dp[i] + dp[i - nums[j]]，需要注意的dp的类型，针对于某一个官方用例，即target=999的情况，
// 在该情况中，中间值可能会大于INT_MAX
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j]) {
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};
int main(){
    vector<int> nums = {1, 2, 3};
    int target = 4;
    Solution so = Solution();
    cout<<so.combinationSum4(nums, target)<<endl;
    return 0;
}

/*
关于INT_MAX的问题，出错的用例如下： [10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111] target=999
这个用例的答案只有一种，就是9个111 。可以看到前面n-1个数都是10的倍数，是不可能得到和为999的。 但是dp计算的过程中会计算和为0-999所有数字。例如计算dp[990], 排列数目会有很多，可能越界。
最符合理论的解法是：使用unsigned long long, 这样完全满足传递方程， 保证中间计算值不越界。
官方的解法有偷巧的地方，因为最终结果保证不超过INT_MAX, 所以超过就不传递了。实际确实也不传递，假设dp[990] > INT_MAX, dp[999] 实际无法通过dp[990]传递，因为nums里面没有一个值是9.
总结：dp中间值可能大于INT_MAX, 但是目标值是小于INT_MAX的。测试用例特殊，目标值实际不需要中间值（大于INT_MAX)的传递。
*/

/*
错误解法：回溯（TLE）
class Solution {
private:
    int result = 0;
    void backtrack(vector<int>& nums, vector<int>& state, int start, int target) {
        if (target == 0) {
            result += 1;
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (target - nums[i] < 0) {
                break;
            }
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            state.push_back(nums[i]);
            backtrack(nums, state, 0, target - nums[i]);  // backtrack从i开始，i之前的不用再选了
            state.pop_back();
        }
        return;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> state;
        backtrack(nums, state, 0, target);
        return result;
    }
};
*/

