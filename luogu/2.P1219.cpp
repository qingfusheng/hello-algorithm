// 题目名称：[USACO1.5] 八皇后 Checker Challenge
// 题目来源：洛谷
// 题目难度：普及/提高−
// 题目链接：https://www.luogu.com.cn/problem/P1219
// 题目思路：回溯思想
// 备注：默认加了O2，不清楚没加O2的情况
#include<iostream>
#include<vector>
using namespace std;
int N;
int tcount = 0;
void dfs(vector<int>& nums, vector<int>&state, vector<bool>&selected, vector<vector<int>>&res) {
	if (state.size() == nums.size()) {
		if(res.size()<3)
			res.push_back(state);
		tcount += 1;
		return;
	}
	for (int i = 0; i < nums.size(); i++) {
		int num = nums[i];
        // 剪枝1（行，列，即不重复选择），跟全排列的思想很相似
		if (!selected[i]) {
			bool flag = false;
			// 剪枝2（正反对角线）
			if (state.size() > 0) {
				int level = state.size();
				for (int j = 0; j < state.size(); j++) {
					if ((level + i) == (j + state[j]) || (j + i) == (level + state[j]))
						flag = true;
				}
			}
			if (flag)
				continue;
			selected[i] = true;
			state.push_back(i);
			dfs(nums, state, selected, res);
			selected[i] = false;
			state.pop_back();
		}
	}
}
vector<vector<int>> NQueen(vector<int> nums) {
	vector<int> state;
	vector<bool> selected(nums.size(), false);
	vector<vector<int>> result;
	dfs(nums, state, selected, result);
	return result;
}
int main() {
	cin >> N;
	vector<int> nums(N, 0);
	for (int i = 0; i < N; i++)
		nums[i] = i + 1;
	vector<vector<int>> result = NQueen(nums);
	for (vector<int> res_vector : result) {
		for (int res : res_vector)
			cout << res + 1 << " ";
		cout << "\n";
	}
	cout << tcount << "\n";
}