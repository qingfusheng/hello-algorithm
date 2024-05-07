#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isAlpha(char ch){
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }
public:
    string reverseOnlyLetters(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right){
            while(left < right && !isalpha(s[left]))  left++;
            while(left < right && !isalpha(s[right]))right--;
            if(left >= right)break;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main(){
    Solution s;
    string str = "a-bC-dEf-ghIj";
    cout << s.reverseOnlyLetters(str) << endl;
    return 0;
}