// 排序+滑动窗口（双指针）
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int result = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int i=0,j=0;
        while(i <= j && j < n){
            if(nums[j] - nums[i] <= 2 * k){
                j++;
                result = max(result, j - i);
            }else{
                i++;
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.maximumBeauty(nums, 3) << endl;
    return 0;
}

/*
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; i < n; i++) {
            while (nums[i] - 2 * k > nums[j]) {
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
*/