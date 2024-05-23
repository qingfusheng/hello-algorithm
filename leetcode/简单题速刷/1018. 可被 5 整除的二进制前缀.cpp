#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int cur = 0;
        for(auto&num: nums){
            cur = ((cur << 1) + num) % 5;  // %5为优化
            result.emplace_back(cur == 0);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums = {0,1,1};
    vector<bool> result = s.prefixesDivBy5(nums);
    for(auto& each: result){
        cout << each << " ";
    }
    return 0;
}