// Task: 全排列 A^n_n
#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<int>& nums, vector<int>& state, vector<bool>& selected, vector<vector<int>>& res) {
	if (state.size() == nums.size()) {
		res.push_back(state);
		// 程序出口1，state的size满足要求即返回（往上回溯
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		int num = nums[i];
		if (!selected[i]) {
			selected[i] = true;
			state.push_back(num);
			backtrack(nums, state, selected, res);
			selected[i] = false;
			state.pop_back();
		}
	}
	// 程序出口2，遍历完nums即返回（主要是平级，1-2-3切换1-3-2这种
	return;
}
vector<vector<int>> permutationsI(vector<int> nums) {
	vector<int> state;
	vector<bool> selected(nums.size(), false);
	vector<vector<int>> res;
	backtrack(nums, state, selected, res);
	return res;
}
int main() {
	vector<int> nums{ 1,2,3,4,5 };
	vector<vector<int>> result = permutationsI(nums);
	for (vector<int> each_vector : result) {
		for (int each : each_vector)
			cout << each << " ";
		cout << endl;
	}
	cout << "length:" << result.size();
}