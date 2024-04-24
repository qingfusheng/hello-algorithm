// 二分主要注意边界条件
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right-left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution s;
    cout << s.search(nums, target) << endl;
    return 0;
}