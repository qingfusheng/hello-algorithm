// 题目名称：15. 三数之和
// 题目来源：LeetCode
// 题目难度：普通
// 题目链接：https://leetcode.cn/problems/3sum/description/
// 题目思路：双指针
// 备注：重点是如何构造循环体和去重（也可以直接用Set

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	for (int i = 0; i < nums.size() - 1; i++) {
		if (i > 0 && nums[i] == nums[i - 1]) continue;  // 拒绝i重复
		int left_index = i + 1, right_index = nums.size() - 1;
		if (nums[i] > 0)
			break;
		while (left_index < right_index) {
			if (nums[right_index] < 0)
				break;
			if (nums[i] + nums[left_index] + nums[right_index] == 0) {
				result.push_back({ nums[i],nums[left_index], nums[right_index] });
				while (left_index + 1 < right_index && nums[left_index + 1] == nums[left_index])left_index++;  // 拒绝left_index重复
				while (right_index - 1 > left_index && nums[right_index - 1] == nums[right_index])right_index--; // 拒绝right_index重复
				// 注意这里的条件，i固定的时候，如果nums[left]+nums[right]=-nums[i]，那么肯定无法通过只修改其中一个值（left，right）使其再次达到和为0，因此是left和right指针的共同移动。
				left_index++;
				right_index--;
			}
			else if (nums[i] + nums[left_index] + nums[right_index] > 0) {
				right_index--;
			}else{
				left_index ++;
			}
		}
	}
	return result;
}

int main() {
	vector<int> nums{ -2,0,0,2,2};
	vector<vector<int>> result = threeSum(nums);
	for (auto each_vector : result) {
		for (auto each : each_vector) {
			cout << each << " ";
		}
		cout << endl;
	}
}