// 题目名称：881. 救生艇
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/boats-to-save-people/description
// 题目思路：双指针
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
            sort(people.begin(), people.end());
            int left = 0, right = people.size() - 1, result = 0;
            while(left <= right){
                if(people[right] + people[left] > limit || left == right){
                    result++;
                    right--;
                }else{
                    left++, right--;
                    result++;
                }
            }
            return result;
    }
};
int main(){
    Solution s;
    vector<int> people = {3,2,2,1};
    int limit = 3;
    cout << s.numRescueBoats(people, limit) << endl;
    return 0;
}