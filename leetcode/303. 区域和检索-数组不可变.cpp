// 题目名称：303. 区域和检索 - 数组不可变
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/range-sum-query-immutable/description
// 题目思路：前缀和
// 备注：this->pre_sum[right] - this->pre_sum[left-1]来解决left!=0的情况
// Definition for singly-linked list.
#include<iostream>
#include<vector>

using namespace std;
class NumArray {
private:
    vector<int> pre_sum;
public:
    NumArray(vector<int>& nums) {
        pre_sum = vector<int>(nums.size());
        pre_sum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            pre_sum[i] = pre_sum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if(left == 0)
            return this->pre_sum[right];
        else
            return this->pre_sum[right] - this->pre_sum[left-1];
    }
};

int main() {
    vector<int> nums = { -2, 0, 3, -5, 2, -1 };
    NumArray* num_array = new NumArray(nums);
    int result = num_array->sumRange(0, 2);
    cout << result << endl;
    return 0;
}