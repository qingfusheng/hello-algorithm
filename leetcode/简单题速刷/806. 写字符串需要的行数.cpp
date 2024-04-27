#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line = 1;
        int cur = 0;
        for(int i = 0; i < s.size(); i++){
            cur += widths[s[i] - 'a'];
            if(cur > 100){
                line += 1;
                cur = widths[s[i] - 'a'];
            }
        }
        return vector<int>{line, cur};
    }
};

int main(){}
// 注意width是从'a'到'z'的宽度