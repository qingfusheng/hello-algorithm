#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};

int main(){
    Solution s;
    string str = "abab";
    cout << s.repeatedSubstringPattern(str) << endl;
}

// 很巧妙的做法，实际上是抄的题解