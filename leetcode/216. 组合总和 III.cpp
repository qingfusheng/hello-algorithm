// 题目名称：216. 组合总和 III
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/combination-sum-iii/description
// 题目思路：回溯
// 备注：注意，这里要求的是不重复，因此backtrack的时候，需要是从i+1开始，而不再是i

#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
class Solution {
private:
	vector<int> candidates = { 1,2,3,4,5,6,7,8,9 };
	void backtrack(vector<int>& state, int start, vector<vector<int>>& res, int target, int k) {
		if (target == 0 && state.size() == k){
			res.push_back(state);
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			if (target - candidates[i] < 0) {
				break;
			}
			if (i > start && candidates[i] == candidates[i - 1]) {
				continue;
			}
			state.push_back(candidates[i]);
			backtrack(state, i + 1, res, target - candidates[i], k);  // backtrack从i开始，i之前的不用再选了
			state.pop_back();
		}
		return;
	}
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		// n->target
		vector<int> state;
		vector < vector<int>> result;
		backtrack(state, 0, result, n, k);
		return result;
	}
};



int main() {
	int k = 3;
	int target = 7;
	Solution so = Solution();
	vector<vector<int>> result = so.combinationSum3(k, target);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
// 官方的枚举思路，不是很理解，不过应该跟backtrack思路差不多
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k, int sum) {
        if (temp.size() + (n - cur + 1) < k || temp.size() > k) {
            return;
        }
        if (temp.size() == k && accumulate(temp.begin(), temp.end(), 0) == sum) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(cur);
        dfs(cur + 1, n, k, sum);
        temp.pop_back();
        dfs(cur + 1, n, k, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, 9, k, n);
        return ans;
    }
};

*/