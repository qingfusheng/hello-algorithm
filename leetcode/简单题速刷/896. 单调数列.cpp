// 极其不优雅的方法
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1)return true;
        bool unset = true;
        bool up = true;
        int index = 0;
        while(unset && index + 1 < nums.size()){
            if(nums[index] == nums[index+1])
                index ++;
            else{
                unset = false;
            }
        }
        if(unset){
            return true;
        }else{
            up = (nums[index] < nums[index + 1]);
        }
        for(int i=1;i<nums.size();i++){
            if(up){
                if(nums[i] < nums[i-1]){
                    return false;
            }
            }else{
                if(nums[i] > nums[i - 1]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,2,3};
    cout << s.isMonotonic(nums) << endl;
    return 0;
}

/*
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                inc = false;
            }
            if (nums[i] < nums[i + 1]) {
                dec = false;
            }
        }
        return inc || dec;
    }
};

*/