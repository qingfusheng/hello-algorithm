// 题目名称：2549. 统计桌面上的不同数字
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/count-distinct-numbers-on-board/description
// 题目思路：脑筋急转弯
// 备注：注意n==1的情况即可
// Definition for singly-linked list.
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int distinctIntegers(int n) {
	if (n == 1)return 1;
	int count = n - 1;
	for (int i = 2; i <= n - i; i++) {
		bool flag = false;
		for (int j = i + 1; j <= n - 1; j++) {
			if (j % i == 1) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			count--;
		}
	}
	return count;
}

int main() {
	int n=100;
	int result = distinctIntegers(n);
	cout<<result<< endl;
}


/*
 *脑筋急转弯xs，一个值n必然会有n-1使得（n%(n-1))==1(除了2),所以只需要返回n-1即可
 * 
class Solution {
public:
	int distinctIntegers(int n) {
		if (n == 1)return 1;
		else return n - 1;
	}
};
 */