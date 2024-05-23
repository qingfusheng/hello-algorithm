// 哈希表+滑动窗口
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
		unordered_map<int, vector<int>> Pos;
		for (int i = 0; i < nums.size(); i++) {
			Pos[nums[i]].push_back(i);
		}
		int ans = 0;
		for (auto& kv : Pos) {
			vector<int>& vec = kv.second;
			for (int i = 0, j = 0; i < vec.size(); i++) {
				while ((vec[i] - vec[j] - (i - j)) > k) {
					j++;
				}
				ans = max(ans, i - j + 1);
			}
		}
		return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,2,3,1,3};
    int k = 3;
    cout << s.longestEqualSubarray(nums, k) << endl;
    return 0;
}