#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int max_val = INT_MIN, min_val = INT_MAX;
        for(auto &num: nums){
            if(num > max_val)max_val = num;
            if(num < min_val)min_val = num;
        }
        return max(max_val-min_val - 2 * k, 0);
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 3, 6};
    cout << s.smallestRangeI(nums, 3) << endl;
}