// 题目名称：4. 寻找两个正序数组的中位数
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
// 题目思路：不用合并，只需要找到中位数的位置即可，时间复杂度O(m+n)，普通题目
// 备注：普通解法

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m1=0, m2=0;
	int len1 = nums1.size(), len2 = nums2.size();
	int index1 = 0, index2 = 0;
	for (int total_index = 0; total_index < len1 + len2; total_index++) {
		int temp=0;
		if ((index1 < len1 && index2 < len2)) {
			if (nums1[index1] < nums2[index2]) {
				temp = nums1[index1];
				index1 += 1;
			}
			else {
				temp = nums2[index2];
				index2 += 1;
			}
		}
		else if (index1 < len1 && index2 >= len2) {
			temp = nums1[index1];
			index1 += 1;
		}
		else if (index1 >= len1 && index2 < len2) {
			temp = nums2[index2];
			index2 += 1;
		}
		if (total_index == (len1 + len2) / 2 - 1)
			m1 = temp;
		if (total_index == (len1 + len2) / 2) {
			m2 = temp;
			break;
		}
	}
	cout << m1 << ", " << m2 << endl;
	if ((len1 + len2) % 2 == 0) {
		return (double)(m1+m2)/2;
	}
	else {
		return m2;
	}
}
int main() {
	vector<int> nums1 = { 1,3,5,6,7 };
	vector<int> nums2 = { 2 };
	double result = findMedianSortedArrays(nums1, nums2);
	printf("%llf", result);
	return 0;
}