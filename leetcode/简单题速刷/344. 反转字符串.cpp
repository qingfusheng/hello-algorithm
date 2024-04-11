#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

/*
// 双指针，效率较低
class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() <= 1)return;
        int left = 0, right = s.size() - 1;
        while(left < right){
            swap(s[left++], s[right--]);
        }
    }
};
*/