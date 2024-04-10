#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == mid){
                left = mid + 1;
            }else if(nums[mid] > mid){
                right = mid - 1;
            }
        }
        return left;
    }
};

int main(){
    vector<int> nums = {0,1,3};
    Solution s;
    cout << s.missingNumber(nums);
}
/*排序然后二分*/


/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long total = n * (n + 1) / 2;  // 主要是怕它存不下
        for(int i=0;i<nums.size();i++)
            total -= nums[i];
        return total;
    }
};
*/

/*
也可以用异或的方法，因为两个相同的数异或为0
*/