#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       unordered_map<int, int>MyMap;
       int n = nums.size();
       int res1, res2;
       for(int num: nums){
        if(MyMap.find(num)!=MyMap.end()){
            res1 = num;
        }else{
            MyMap[num] = 1;
        }
       }
       for(int i=1;i<=n;i++){
        if(MyMap.find(i) == MyMap.end())res2 = i;
       }
       return vector<int>{res1, res2};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 2, 4};
    vector<int> res = sol.findErrorNums(nums);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}
/*总之，用哈希是一种很慢的方法*/

/*
# Python3
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        num1 = sum(range(1, len(nums)+1)) - sum(set(nums))
        num2 = sum(nums) - sum(set(nums))
        return [num2, num1]
*/