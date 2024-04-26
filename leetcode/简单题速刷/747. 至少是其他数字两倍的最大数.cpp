// 找到最大值和第二大值，判断最大值是否大于第二大值的两倍
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_val = -1, less_max_val = -1;
        int max_val_index = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > max_val){
                less_max_val = max_val;
                max_val = nums[i];
                max_val_index = i;
            }else{
                if(nums[i] > less_max_val){
                    less_max_val = nums[i];
                }
            }
        }
        return max_val >= 2 * less_max_val ? max_val_index : -1;

    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 6, 1, 0};
    cout << s.dominantIndex(nums) << endl;
}