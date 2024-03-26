// 题目名称：11. 盛最多水的容器
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/container-with-most-water/description/
// 题目思路：双指针
// 备注：双指针，左右指针分别指向容器的左右边界，然后向中间移动，每次移动较短的那个边界，直到左右指针相遇

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int maxArea(vector<int>& height) {
	int max_area = 0;
	int left_index = 0, right_index = height.size() - 1;
	while (left_index < right_index) {
		if (height[left_index] < height[right_index]) {
			max_area = max(max_area, (right_index - left_index) * height[left_index++]);
		}
		else {
			max_area = max(max_area, (right_index - left_index) * height[right_index--]);
		}
	}
	return max_area;
}
int main() {
	vector<int> height{ 1,8,6,2,5,4,8,3,7 };
	int result = maxArea(height);
	cout << result << endl;
	return 0;
}