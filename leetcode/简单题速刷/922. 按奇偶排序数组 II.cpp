#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int odd = 1, even = 0;
        while(odd < n && even < n){
            while(odd < n && nums[odd] % 2 == 1)odd += 2;
            while(even < n && nums[even] % 2 == 0) even += 2;
            if(odd >=n || even >= n)break;
            swap(nums[odd], nums[even]);
            odd += 2, even += 2;
        }
        return nums;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,2,5,7};
    vector<int> res = s.sortArrayByParityII(nums);
    for(auto i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}