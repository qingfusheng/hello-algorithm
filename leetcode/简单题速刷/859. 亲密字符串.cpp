#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())return false;
        unordered_map<int, int> MyMap;
        bool hasDouble = false;
        for(auto &ch: s){
            if(MyMap[ch]){
                MyMap[ch] += 1;
                hasDouble = true;
            }else{
                MyMap[ch] = 1;
            }
        }
        if(s == goal)
            if(hasDouble)
                return true;
            else
                return false;

        vector<vector<char>> temp;
        for(int i = 0;i<s.length();i++){
            if(s[i] != goal[i]){
                temp.push_back(vector<char>{s[i], goal[i]});
                if(temp.size() > 2)return false;
            }
        }
        if(temp.size() == 1)return false;
        return temp[0][1] == temp[1][0] && temp[0][0] == temp[1][1];
    }
};

int main(){
    Solution s;
    cout << s.buddyStrings("ab", "ba") << endl;
    cout << s.buddyStrings("ab", "ab") << endl;
    cout << s.buddyStrings("aa", "aa") << endl;
    cout << s.buddyStrings("aaaaaaabc", "aaaaaaacb") << endl;
    cout << s.buddyStrings("", "aa") << endl;
    return 0;
}