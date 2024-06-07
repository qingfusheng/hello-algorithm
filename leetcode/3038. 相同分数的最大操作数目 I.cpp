#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int result = 1;
        int n = nums.size();
        int pre = nums[0] + nums[1];
        for(int i=1;i<n/2;i++){
            if(nums[2*i] + nums[2*i+1] == pre){
                result++;
            }else{
                break;
            }
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout << s.maxOperations(nums) << endl;
    return 0;
}