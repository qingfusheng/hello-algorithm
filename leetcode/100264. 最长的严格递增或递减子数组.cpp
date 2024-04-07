// 题目名称：100264. 最长的严格递增或递减子数组
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
// 题目思：遍历数组，判断当前元素与前一个元素的大小关系，如果是递增或递减，则计数器加一，否则重置计数器为1，最后返回计数器的最大值

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_length = 1;
        int temp_count = 1;
        bool is_increasing=true, is_decreasing = true;
        for (int i = 1; i < nums.size(); i++) {
            cout << nums[i] << ":" << endl;
            if (nums[i] == nums[i - 1]) {
                is_increasing = true;
                is_decreasing = true;
                temp_count = 1;
            }
            if (is_increasing && nums[i] > nums[i - 1]) {
                cout << "increasing" << endl;
                temp_count++;
                max_length = max(max_length, temp_count);
                is_increasing = true;
                is_decreasing = false;
            }
            else if (is_decreasing && nums[i] < nums[i - 1]) {
                cout << "decreasing" << endl;
                temp_count++;
                max_length = max(max_length, temp_count);
                is_increasing = false;
                is_decreasing = true;
            }
            else {
                cout << "broken" << endl;
                temp_count = 1;
                if (nums[i] > nums[i - 1]) {
                    is_increasing = true;
                    is_decreasing = false;
                    temp_count += 1;
                }
                else if (nums[i] < nums[i - 1]) {
                    is_increasing = false;
                    is_decreasing = true;
                    temp_count += 1;
                }
            }
        }
        return max_length;
    }
};

int main() {
    Solution so = Solution();
    //vector<int> nums = { 1,9,7,1 };
    vector<int> nums = { 1,4,3,3,2};
    int result = so.longestMonotonicSubarray(nums);
    cout << result << endl;
}