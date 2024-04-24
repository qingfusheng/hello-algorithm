#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> MyMap;
        int max_val = 0;
        for (auto& num : nums) {
            if (MyMap.find(num) != MyMap.end()) {
                MyMap[num] += 1;
                max_val = max(max_val, MyMap[num]);
            }
            else {
                MyMap[num] = 1;
            }
        }
        vector<int> candidates;
        for (auto& kv : MyMap) {
            if (kv.second == max_val)candidates.push_back(kv.first);
        }
        int res = INT_MAX;
        for (int each : candidates) {
            int left = 0, right = nums.size() - 1;
            while (nums[left] != each)left++;
            while (nums[right] != each) right--;
            res = min(res, right - left);
        }
        return res == INT_MAX ? 1 : res + 1;
    }
};

int main() {
    Solution s;
	vector<int> nums = { 1 };
	cout << s.findShortestSubArray(nums) << endl;
	return 0;
}

/*
题解：https://leetcode.cn/problems/degree-of-an-array/solutions/2754010/ha-xi-biao-wo-ye-bu-zhi-dao-ying-gai-jia-3lnz/
*/