// 题目名称：209. 长度最小的子数组
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/minimum-size-subarray-sum/description/
// 题目思路：暴力会超时，滑动窗口

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = 0;
        int sum = 0;
        int min_length = INT_MAX;
        while (end < n) {
            sum += nums[end];
            while (sum >= target) {
                min_length = min(min_length, end - start + 1);
                sum -= nums[start++];
            }
            end++;
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
};
int main() {
    Solution s;
	vector<int> nums = { 2,3,1,2,4,3 };
	int target = 7;
	cout << s.minSubArrayLen(target, nums);
	return 0;
}

/*
前缀和+二分：
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); 
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
*/

/*
前缀和+暴力：
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> pre(nums.size() + 1, 0);
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target)return 1;
            pre[i + 1] = pre[i] + nums[i];
        }
        int min_length = INT_MAX;
        for(int i=pre.size()-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(pre[i]-pre[j] >= target){
                    min_length = min(min_length, i - j);
                    break;
                }
            }
        }
        return min_length == INT_MAX?0:min_length;
    }
};
*/