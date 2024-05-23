#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> st;
        for (auto c : s) {
            if (c == ')') {
                st.pop();
            }
            if (!st.empty()) {
                res.push_back(c);
            }
            if (c == '(') {
                st.emplace(c);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.removeOuterParentheses("(()())(())") << endl;
    cout << s.removeOuterParentheses("(()())(())(()(()))") << endl;
    cout << s.removeOuterParentheses("()()") << endl;
    return 0;
}