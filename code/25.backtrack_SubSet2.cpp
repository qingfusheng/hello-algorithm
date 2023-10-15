// 省略了total参数，使用target的减法代替；使用排序，确保无重复序列
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* 回溯算法：子集和 I */
void backtrack(vector<int>& state, int target, vector<int>& choices, int start, vector<vector<int>>& res) {
    // 子集和等于 target 时，记录解(减去了total参数）
    if (target == 0) {
        res.push_back(state);
        return;
    }
    // 遍历所有选择
    // 剪枝二：从 start 开始遍历，避免生成重复子集
    for (int i = start; i < choices.size(); i++) {
        // 剪枝一：若子集和超过 target ，则直接结束循环
        // 这是因为数组已排序，后边元素更大，子集和一定超过 target
        if (target - choices[i] < 0) {
            break;
        }
        // 尝试：做出选择，更新 target, start
        state.push_back(choices[i]);
        // 进行下一轮选择
        backtrack(state, target - choices[i], choices, i, res);
        // 回退：撤销选择，恢复到之前的状态
        state.pop_back();
    }
}

/* 求解子集和 I */
vector<vector<int>> subsetSumI(vector<int>& nums, int target) {
    vector<int> state;              // 状态（子集）
    sort(nums.begin(), nums.end()); // 对 nums 进行排序
    int start = 0;                  // 遍历起始点
    vector<vector<int>> res;        // 结果列表（子集列表）
    backtrack(state, target, nums, start, res);
    return res;
}

int main() {
    vector<int> nums{ 2,3,4,5 };
    int target = 9;
    vector<vector<int>> result = subsetSumI(nums, target);
    for (vector<int> each_vector : result) {
        for (int each : each_vector)
            cout << each << " ";
        cout << endl;
    }
}