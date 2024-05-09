// 题目名称：2105. 给植物浇水 II
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/watering-plants-ii/description/
// 题目思路：双指针，贪心
// 备注：只需要考虑当前的plant就好，而不是它的下一个（那样情况会复杂很多），以及注意当index1==index2的情况

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int cur1 = capacityA, cur2 = capacityB;
        int left = 0, right = plants.size() - 1;
        int result = 0;
        while(left < right){
            if(cur1 < plants[left]){
                result++;
                cur1 = capacityA;
            }
            cur1 -= plants[left++];

            if(cur2 < plants[right]){
                result++;
                cur2 = capacityB;
            }
            cur2 -= plants[right--];

            if(left == right  && max(cur1, cur2) <plants[left]){
                result++;
            }
        }
        return result;
        
    }
};

int main(){
    Solution s;
    vector<int> plants = {2, 4, 5, 1, 2};
    int capacityA = 5, capacityB = 7;
    cout << s.minimumRefill(plants, capacityA, capacityB) << endl;
    return 0;
}