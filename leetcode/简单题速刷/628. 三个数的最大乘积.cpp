#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(nums[n-1] * nums[n-2] * nums[n-3], nums[0] * nums[1] * nums[n-1]);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.maximumProduct(nums) << endl;
    return 0;
}

//算起来应该会有很懂情况，选中的三个都是正的（选最大的正数），选中的有两个是正的（选最大的负数，以及最小的正数<只有两个，不然怎么会选到负数>）， 有两个是负的（选两个负数和一个整数），以及三个都是负（选最大的三个负数，即后三个）的情况

// 还有一种并查集的思路