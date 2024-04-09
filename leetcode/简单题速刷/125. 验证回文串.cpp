#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        bool isHW = true;
        while(left<=right){
            if(!((s[left]>='A'&&s[left]<='Z') || (s[left]>='a'&&s[left]<='z') || (s[left] >='0'&&s[left]<='9'))){left++;continue;}
            if(!((s[right]>='A'&&s[right]<='Z') || (s[right]>='a'&&s[right]<='z') || (s[right] >='0'&&s[right]<='9'))){right--;continue;}
            if(s[left]>='A'&&s[left]<='Z')
                s[left] += 32;
            if(s[right]>='A'&&s[right]<='Z')
                s[right] += 32;
            if(s[left] == s[right]){
                left++, right--;
                continue;
            }else{
                isHW = false;
                break;
            }
        }
        return isHW;
    }
};
int main(){
    
}

/*
 * // leetcode官方解法，使用isalnum和tolower函数，以及借助一个新的字符串结构
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right) {
           if (sgood[left] != sgood[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
*/

/*
* // 自己的解法，使用isalnum和tolower函数
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left<=right){
            if(!isalnum(s[left])){left++;continue;}
            if(!isalnum(s[right])){right--;continue;}
            if(tolower(s[left]) == tolower(s[right])){
                left++, right--;
            }else{
                return false;
            }
        }
        return true;
    }
};
*/