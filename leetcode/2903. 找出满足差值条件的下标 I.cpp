// 题目名称：2903. 找出满足差值条件的下标 I
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i/description/
// 题目思路：双指针，枚举
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int left = 0, right = left + indexDifference;
        for(int left = 0 ; left + indexDifference < nums.size();left ++){
            for(int right = left + indexDifference; right < nums.size(); right ++){
                if(abs(nums[right]-nums[left]) >= valueDifference){
                    return vector<int>{left, right};
                }
            }
        }
        return {-1, -1};
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 6, 1, 0};
    int indexDifference = 2;
    int valueDifference = 2;
    vector<int> result = s.findIndices(nums, indexDifference, valueDifference);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}