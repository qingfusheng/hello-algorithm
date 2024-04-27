#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n);

        for (int i = 0, idx = -n; i < n; ++i) {
            if (s[i] == c) {
                idx = i;
            }
            ans[i] = i - idx;
        }

        for (int i = n - 1, idx = 2 * n; i >= 0; --i) {
            if (s[i] == c) {
                idx = i;
            }
            ans[i] = min(ans[i], idx - i);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> ans = s.shortestToChar("loveleetcode", 'e');
    for(auto x: ans){
        cout << x << " ";
    }
    return 0;
}