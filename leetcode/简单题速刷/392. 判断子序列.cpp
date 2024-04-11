#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index1 = 0, index2 = 0;
        while(index2 < t.length()){
            if(s[index1] == t[index2]){
                index1++, index2++;
            }else{
                index2++;
            }
        }
        return index1==s.length();
    }
};

int main(){
    Solution s;
    cout << s.isSubsequence("abc", "ahbgdc") << endl;
}

/*
双指针，子序列
*/