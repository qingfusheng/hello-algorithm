// 题目名称：1535. 找出数组游戏的赢家
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/find-the-winner-of-an-array-game/description/
// 题目思路: 模拟，注意k大于数组长度的情况
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int length = arr.size();
        if(k >= length){
            return *max_element(arr.begin(), arr.end());
        }
        int pre_max = arr[0];
        int temp_length = 0;
        int cur_index = 0;
        while(++cur_index < length){
            if(arr[cur_index] < pre_max){
                temp_length ++;
            }else{
                pre_max = arr[cur_index];
                temp_length = 1;
            }
            if(temp_length == k){
                return pre_max;
            }
        }
        return pre_max;

    }
};

int main(){
    Solution s;
    vector<int> arr = {2,1,3,5,4,6,7};
    int k = 2;
    cout << s.getWinner(arr, k) << endl;
    return 0;
}