#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i=0;i<nums.size() ;i+=2){
            sum += nums[i];
        }
        return sum;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,4,3,2};
    cout << s.arrayPairSum(nums) << endl;
    return 0;
}

/*
//！！！需要注意的是，
        for(int i=0;i<nums.size() ;i+=2)sum += nums[i]; 
        比
        for(int i=0;i<nums.size()/2;i++)sum+= nums[2*i];
        快了将近一倍？
*/