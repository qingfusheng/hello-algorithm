// 题目名称：2917. 找出数组中的 K-or 值
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/find-the-k-or-of-an-array/description/
// 题目思路：位运算

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        for(int i=0; i < 31; i++){
            int count = 0;
            for(auto num: nums){
                count += num >> i & 1;
                if(count >= k)break;
            }
            if(count >= k){
                ans = ans | 1 << i;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << s.findKOr(nums, 4) << endl;
}