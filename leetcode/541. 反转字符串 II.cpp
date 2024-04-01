// 题目名称：541. 反转字符串 II
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/reverse-string-ii/description/
// 题目思路：字符串
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        string res = "";
        string temp;
        bool nd_reverse = true;
        for(int index = 0; index < s.length() / k; index ++){
            temp = s.substr(index * k, k);
            if(index % 2 == 0){
                reverse(temp.begin(), temp.end());
                nd_reverse = false;
            }else{
                nd_reverse = true;
            }
            res += temp;
        }
        if(s.length() % k !=0){
            temp = s.substr(k * (int)(s.length() / k), s.length() % k);
            if(nd_reverse){
                reverse(temp.begin(), temp.end());
            }
            res += temp;
        }
        return res;
    }
};
int main(){
    Solution s;
    string str = "abcdefg";
    int k = 2;
    cout<<s.reverseStr(str, k)<<endl;
    return 0;
}


/*
 * 简化代码：（原来reverse(s.begin(), s.end())允许任意子串的reverse）

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int index = 0; index * k < s.length(); index+=2) {
            if (index < s.length() / k)
                reverse(s.begin() + index * k, s.begin() + (index + 1) * k);
            else
                reverse(s.begin() + index * k, s.begin() + min((index+1) * k, (int)s.length()));
        }
        return s;
    }
};

*/