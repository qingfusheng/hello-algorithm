#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> MySet(nums.begin(), nums.end());
        nums = vector<int>(MySet.begin(), MySet.end());
        if(nums.size() == 1)return nums[0];
        if(nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        sort(nums.begin(), nums.end());
        return nums[nums.size() - 3];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 2, 5, 3, 5};
    cout << s.thirdMax(nums) << endl;
}

/*
去重，排序
*/