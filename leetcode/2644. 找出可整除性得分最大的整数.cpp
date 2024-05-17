// https://leetcode.cn/problems/find-the-maximum-divisibility-score/description/?
// 注意官方题解的第二个优化
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int max_score = 0;
        int max_index = 0;
        sort(divisors.begin(), divisors.end());
        sort(nums.begin(), nums.end(), std::greater());

        for(int i=0;i<divisors.size();i++){
            int score = 0;
            for (auto &num: nums){
                if(divisors[i] > num){
                    break;
                }else{
                    if(num % divisors[i] == 0){
                        score += 1;
                    }
                }
            }
            if(score > max_score){
                max_index = i;
                max_score = score;
            }
        }
        return divisors[max_index];
    }
};

int main(){
    Solution s;
    vector<int> nums = {3, 2, 5, 7};
    vector<int> divisors = {2, 3, 5, 7};
    cout << s.maxDivScore(nums, divisors) << endl;
    return 0;
}