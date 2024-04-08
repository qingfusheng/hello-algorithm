// 题目名称：2009. 使数组连续的最少操作数
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous/description/
// 题目思路：首先对nums进行去重和排序，然后根据区间[nums[i], nums[i] + n - 1]进行判断落在区间中的元素个数，取剩下元素的最小值
// 备注：被提示误导了，二分查找会超时，只需要判断元素是否落在那个区间内即可

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int min_cost = INT_MAX;
        unordered_set<int> cnt(nums.begin(), nums.end());  // 去重
        vector<int> sortedUniqueNums(cnt.begin(), cnt.end());  // set转vector
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());  // 排序
        int n = nums.size();
        int res = n, j = 0;
        for (int i = 0; i < sortedUniqueNums.size(); i++) {
            int right = sortedUniqueNums[i] + n - 1;
            while (j < sortedUniqueNums.size() && sortedUniqueNums[j] <= right) {
                res = min(res, n - (j - i + 1));  // 并不需要对每一个元素进行二分查找，只需要对在区间内的元素进行计数即可
                j++;
            }
        }
        return res;
    }
};


int main() {
    Solution so = Solution();
    vector<int> nums = {1,30,31,32,40};
    int result = so.minOperations(nums);
    cout << result << endl;
}


/*
// 过了50/62个测试用例，超时了（就硬搜

class Solution {
private:
    bool bionarySearch(vector<int>& nums, int target) {

        int left = 1, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
public:
    int minOperations(vector<int>& nums) {
        int min_cost = INT_MAX;
        unordered_set<int> cnt(nums.begin(), nums.end());
        vector<int> sortedUniqueNums(cnt.begin(), cnt.end());
        sort(sortedUniqueNums.begin(), sortedUniqueNums.end());
        for (int index = 0; index < sortedUniqueNums.size(); index++) {
            int count = 0;
            int min_Val = sortedUniqueNums[index];
            for (int i = min_Val + 1; i < min_Val + nums.size(); i++) {
                if (!bionarySearch(sortedUniqueNums, i)) {
                    count++;
                }
            }
            if (count < min_cost) {
                min_cost = count;
            }
        }
        return min_cost;
    }
};
*/