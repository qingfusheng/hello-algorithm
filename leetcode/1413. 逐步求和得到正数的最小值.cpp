#include <bits/stdc++.h>
using namespace std;

// 只需要存储上一个元素，不需要直接修改nums[i]
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_val = nums[0];
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
            min_val = min(min_val, nums[i]);
        }
        return min_val >= 1 ? 1 : 1 - min_val;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-3,2,-3,4,2};
    cout << s.minStartValue(nums) << endl;
    return 0;
}