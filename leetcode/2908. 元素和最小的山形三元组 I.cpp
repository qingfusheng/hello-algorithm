// 题目名称：2908. 元素和最小的山形三元组 I
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/minimum-sum-of-mountain-triplets-i/description/
// 题目思路：枚举；前缀最小值
// 备注：枚举的时间复杂度为O(n^3)，可以通过前缀最小值的方法将时间复杂度降低到O(n

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int minimumSum(vector<int>& nums) {
    // 从左到右遍历，计算前缀数据的最小值，这样可以避免枚举时的重复计算，并将时间复杂度从O(n^3)降低到O(n)，同时空间复杂度升到O(n)
    vector<int> min_left(nums.size(), nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        min_left[i] = min(min_left[i-1], nums[i]);
    }
    int result = INT_MAX;
    int right = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 1; i--) {
        if(min_left[i-1] < nums[i] && right<nums[i])
            result = min(result, min_left[i-1] + nums[i] + right);
        right = min(right, nums[i]);
    }
    return result==INT_MAX?-1:result;
}

int main() {
    vector<int> nums{ 5,4,8,7,10,2 };
    int result = minimumSum(nums);
    cout << result << endl;
}

/*
* // 枚举的方法
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int min_value = INT_MAX;
        for (int j = 1; j < nums.size() - 1; j++) {
            for (int i = 0; i < j; i++) {
                if (nums[i] < nums[j])
                    for (int k = j + 1; k < nums.size(); k++) {
                        if (nums[k] < nums[j]) {
                            if (nums[i] + nums[j] + nums[k] < min_value) {
                                min_value = nums[i] + nums[j] + nums[k];
                            }
                        }
                    }
            }
        }
        if (min_value == INT_MAX) {
            return -1;
        }
        else
            return min_value;
    }
};
*/