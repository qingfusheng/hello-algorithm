// 题目名称：2028. 找出缺失的观测数据
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/find-missing-observations/description/
// 题目思路：模拟
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = (m + n) * mean;
        int cur_sum = accumulate(rolls.begin(), rolls.end(), 0);
        int temp = total - cur_sum;
        if(temp > n * 6 || temp < n * 1){
            // 额外注意 temp < n的条件
            return vector<int>();
        }else{
            vector<int> result = vector<int>(n, temp / n);
            int index = 0;
            int temp1 = temp % n;
            while(temp1-- > 0){
                result[index++] += 1;
            }
            return result;
        }
    }
};

int main(){
    Solution s;
    vector<int> rolls = {1, 5, 6};
    int mean = 3;
    int n = 4;
    vector<int> result = s.missingRolls(rolls, mean, n);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}