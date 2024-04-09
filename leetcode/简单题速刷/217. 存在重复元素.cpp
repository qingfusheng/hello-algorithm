#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] == cur){
                return true;
            }else{
                cur = nums[i];
            }
        }
        return false;
    }
};

/*
// 官方题解，使用哈希表，时间复杂度小，占用空间多
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x: nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};
*/