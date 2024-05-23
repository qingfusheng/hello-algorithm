// 其实有点缝缝补补的嫌疑，应该是测试用例没有覆盖全，所以侥幸通过
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int index = 0;
        int temp = 0;
        while(k > 0){
            if(index == nums.size())index --;
            if(nums[index] <= 0){
                nums[index] = (-1) * nums[index];
            }else{
                if(k % 2 == 0){
                    break;
                }else{
                    temp = (index == 0 ? nums[index] : (nums[index] < nums[index - 1] ? nums[index] : nums[index - 1]));
                }
            }
            k--;
            index ++;
        }
        return accumulate(nums.begin(),nums.end(),0) - 2 * temp;

    }
};

int main(){
    Solution s;
    vector<int> nums = {4,2,3};
    int k = 1;
    cout << s.largestSumAfterKNegations(nums, k) << endl;
    return 0;
}

/*
// 更优雅， 但是两次排序导致效率有些下降
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(k > 0 && nums[i] < 0){
                k--;
                nums[i] = -1 * nums[i];
            }
            sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        return sum - (k % 2 == 0 ? 0 : 2 * nums[0]);
    }
};
*/