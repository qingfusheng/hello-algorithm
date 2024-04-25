#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(total - sum - nums[i] == sum)
                return i;
            else
                sum += nums[i];
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << s.pivotIndex(nums) << endl;
    return 0;
}
// 可以适当的考虑一下边界条件，比如只有一个元素的情况