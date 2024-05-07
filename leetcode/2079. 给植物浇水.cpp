// 题目名称：2079. 给植物浇水
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/watering-plants/description/
// 题目思路：数组，模拟

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int cur = capacity;  // 当前水量
        int length = 0;  // 浇水的长度
        for(int i = 0; i < plants.size(); i++){
            if(cur >= plants[i]){
                cur -= plants[i];
                if(i < plants.size() - 1){
                    if(cur < plants[i + 1]){
                        length += 2 * (i + 1);
                        cur = capacity;
                    }
                }else{
                    length += i + 1;
                }
            }
        }
        return length;
    }
};

int main(){
    Solution s;
    // vector<int> plants = {2,4,5,1,2};
    vector<int> plants = {3,2,4,1,1};
    int capacity = 6;
    cout << s.wateringPlants(plants, capacity) << endl;
    return 0;
}