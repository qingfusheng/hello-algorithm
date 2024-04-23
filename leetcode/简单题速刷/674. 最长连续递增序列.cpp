#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int pre = nums[0];
        int temp = 1;
        int max_temp = temp;
        for(int i=1;i<n;i++){
            if(nums[i] > pre){
                temp += 1;
            }else{
                max_temp = max(max_temp, temp);
                temp = 1;
            }
            pre = nums[i];
        }
        return max(max_temp, temp);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << sol.findLengthOfLCIS(nums) << endl;
    return 0;
}