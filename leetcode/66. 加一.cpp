// 题目名称：66. 加一
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/plus-one/description/
// 题目思路：简单题

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        bool carry = true;
        for(int i=0;i<digits.size();i++){
            if(carry){
                digits[i] += 1;
                carry = false;
                if(digits[i] > 9){
                    digits[i] = digits[i] % 10;
                    carry = true;
                }
            }
        }
        if(carry)
            digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
int main(){
    Solution solu = Solution();
    vector<int> digits = {9,9,9};
    vector<int> res = solu.plusOne(digits);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}


/*
// 因为是+1，所以并不需要考虑那么多，9999 + 1 = 10000，只需要res[0]=1即可
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for(int i=digits.size() - 1; i >=0; i--){
            if(carry){
                digits[i] += 1;
                carry = false;
                if(digits[i] == 10){
                    digits[i] = 0;
                    carry = true;
                }else{
                    return digits;
                }
            }else{
                return digits;
            }
        }
        if(carry){
            vector<int> res(digits.size() + 1, 0);
            res[0] = 1;
            return res;
        }
        return digits;
    }
};
*/