#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int temp_sum = 0;
        int n = nums.size();
        for(int i=0;i<k;i++){
            temp_sum += nums[i];
        }
        int max_temp_sum = temp_sum;
        for(int i=k;i<n;i++){
            temp_sum = temp_sum - nums[i-k] + nums[i];
            max_temp_sum = max(max_temp_sum, temp_sum);
        }
        return (double) max_temp_sum / k;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << sol.findMaxAverage(nums, k) << endl;
    return 0;
}

/*
  滑动窗口，只需要注意窗口边界的值，中间的值并不需要重复计算
*/