#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            int score = 0;
            for (int j = 0; j < i; j++) {
                if (s[j] == '0') {
                    score++;
                }
            }
            for (int j = i; j < n; j++) {
                if (s[j] == '1') {
                    score++;
                }
            }
            ans = max(ans, score);
        }
        return ans;
    }
};

int main(){
    Solution s;
    string str = "011101";
    cout << s.maxScore(str) << endl;
    return 0;
}