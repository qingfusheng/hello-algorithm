#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};

int main(){
    Solution s;
    cout << s.rotateString("abcde", "cdeab") << endl;
    return 0;
}

/*
陷阱：s和goal的长度可能不一样
解法：查找子串，KMP，或者直接暴力
*/