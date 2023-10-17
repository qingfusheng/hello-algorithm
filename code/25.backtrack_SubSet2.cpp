// Task: 子集
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void backtrack(vector<int>& nums, vector<int>& state, vector<vector<int>>& res, int target, int start) {
	if (target == 0) {
		res.push_back(state);
		return;
	}
    // start起始元素，剪枝操作，避免重复
	for (int i = start; i < nums.size(); i++) {
		// 剪枝操作,因为已排序，因此不需要continue，直接break
        if (target - nums[i] < 0) {
			break;
		}
		// 剪枝四：如果该元素与左边元素相等，说明该搜索分支重复，直接跳过
		if (i > start && nums[i] == nums[i - 1]) {
			// 实质上这里可以在之前就对num做预处理，确保num中无重复元素
			continue;
		}
		state.push_back(nums[i]);
		backtrack(nums, state,  res, target-nums[i], i);  // backtrack从i开始，i之前的不用再选了
		state.pop_back();
	}
	return;
}
vector<vector<int>> SubSetSum(vector<int> nums, int target) {
	vector<int> state;
	vector<vector<int>> res;
	int start = 0;
	sort(nums.begin(), nums.end());
	backtrack(nums, state, res, target, start);
	return res;
}
int main() {
	vector<int> nums{ 2,3,2,4,5 };
	int target = 9;
	vector<vector<int>> result = SubSetSum(nums, target);
	for (vector<int> each_vector : result) {
		for (int each : each_vector)
			cout << each << " ";
		cout << endl;
	}
	cout << "length:" << result.size();
}