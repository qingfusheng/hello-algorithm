// Task: 子集
#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<int>& nums, vector<int>& state, int total, vector<vector<int>>& res, int target) {
	if (total == target) {
		res.push_back(state);
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (total + nums[i] > target) {
			continue;
		}
		state.push_back(nums[i]);
		backtrack(nums, state, total + nums[i], res, target);
		state.pop_back();
	}
	return;
}
vector<vector<int>> SubSetSum(vector<int> nums, int target) {
	vector<int> state;
	int total = 0;
	vector<vector<int>> res;
	backtrack(nums, state, total, res, target);
	return res;
}
int main() {
	vector<int> nums{ 2,3,4,5 };
	int target = 9;
	vector<vector<int>> result = SubSetSum(nums, target);
	for (vector<int> each_vector : result) {
		for (int each : each_vector)
			cout << each << " ";
		cout << endl;
	}
	cout << "length:" << result.size();
}