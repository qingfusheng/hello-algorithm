#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int n;
    vector<int> nums;
    int helper(int start, int end, int target) {
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for (int i = end - 1; i >= start; i--) {
            for (int j = i + 1; j <= end; j++) {
                if (nums[i] + nums[i + 1] == target) { // 删除前两个数
                    f[i][j + 1] = max(f[i][j + 1], f[i + 2][j + 1] + 1);
                }
                if (nums[j - 1] + nums[j] == target) { // 删除后两个数
                    f[i][j + 1] = max(f[i][j + 1], f[i][j - 1] + 1);
                }
                if (nums[i] + nums[j] == target) { // 删除第一个和最后一个数
                    f[i][j + 1] = max(f[i][j + 1], f[i + 1][j] + 1);
                }
            }
        }
        return f[start][end + 1];
    };
public:
    int maxOperations(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        int res1 = helper(2, n - 1, nums[0] + nums[1]); // 删除前两个数
        int res2 = helper(0, n - 3, nums[n - 2] + nums[n - 1]); // 删除后两个数
        int res3 = helper(1, n - 2, nums[0] + nums[n - 1]); // 删除第一个和最后一个数
        return max({res1, res2, res3}) + 1; // 加上第一次操作
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,4};
    cout << s.maxOperations(nums) << endl;
    return 0;
}