#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // 时间复杂度：O(nlogn)，空间复杂度
        int min_width = nums.size()/2;
        cout<<"min_width:"<<min_width<<endl;
        // 时间复杂度：O(n/2)
        for(int i=0;i+min_width<nums.size();i++){
            if(nums[i] == nums[i+min_width])
                return nums[i];
        }
        // 其实不会到这个地方
        return 1;
    }
};
int main(){
    Solution s;
    vector<int> nums = {3,2,3};
    cout<<s.majorityElement(nums)<<endl;
    return 0;   
}