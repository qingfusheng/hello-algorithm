#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> MyMap;
        for (int& num : nums) {
            if (MyMap.find(num) != MyMap.end()) {
                MyMap[num] += 1;
            }
            else {
                MyMap[num] = 1;
            }
        }
        int ans = 0;
        for (auto& kv : MyMap) {
            int num1 = kv.first;
            if (MyMap.find(kv.first - 1) != MyMap.end()) ans = max(ans, kv.second + MyMap[num1 - 1]);
            if (MyMap.find(kv.first + 1) != MyMap.end()) ans = max(ans, kv.second + MyMap[kv.first + 1]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,2,2,5,2,3,7};
    Solution so = Solution();
    cout<<so.findLHS(nums)<<endl;
    return 0;
}

/*
还有一种思路，就是排序只有看连续的两个数，这样就不用map，不过代码没写出来
*/