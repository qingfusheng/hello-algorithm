/*
    组合总和，需要的又是每一条符合条件的路径，所以需要回溯算法。
    见code/25.backtrack_SubSet2.cpp,
    若不需要路径，只需要个数，可以使用动态规划。
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    void backtrack(vector<int>& nums, vector<int>& state, int start, vector<vector<int>>& res, int target) {
        if (target == 0) {
            res.push_back(state);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (target - nums[i] < 0) {
                break;
            }
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            state.push_back(nums[i]);
            backtrack(nums, state, i, res, target - nums[i]);  // backtrack从i开始，i之前的不用再选了
            state.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> state;
        vector < vector<int>> result;
        backtrack(candidates, state, 0, result, target);
        return result;
    }
};

int main(){
    vector<int> candidates = { 2,3,6,7 };
    int target = 7;
    Solution so = Solution();
    vector<vector<int>> result = so.combinationSum(candidates, target);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}