// 题目名称：238. 除自身以外数组的乘积
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/product-of-array-except-self/description/
// 题目思路：前缀和
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> L(n, 1), R(n, 1);
        for(int i = 0; i<n-1;i++){
            L[i + 1] = L[i] * nums[i];
        }
        for(int j=n-1;j>=1;j--){
            R[j - 1] = R[j] * nums[j];
        }
        vector<int> result(n);
        for(int i=0;i<n;i++){
            result[i] = L[i] * R[i];
        }
        return result;

    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> result = s.productExceptSelf(nums);
    for(auto i:result){
        cout << i << " ";
    }
    return 0;
}
/*暴力会超时*/

/*
将空间复杂度压缩至 O(1) 的方法：
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        int R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i];
        }
        return answer;
    }
};
*/