#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left < right){
            while(left < right && nums[left] % 2 == 0){
                left++;
            }
            while(left < right && nums[right] % 2 != 0){
                right--;
            }
            if(left >= right)
                break;
            swap(nums[left++], nums[right--]);
        }
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 1, 2, 4};
    vector<int> res = s.sortArrayByParity(nums);
    for(int i: res){
        cout << i << " ";
    }
    cout << endl;
}