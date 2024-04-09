#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> MyMap;
        unordered_set<char> MySet;
        if(s.length() != t.length())
            return false;
        for(int i=0;i<s.length();i++){
            // 在这里需要注意的是，我是不能够双向绑定的，题目要求是一个满射，所以还需要把y也存起来
            if(MyMap.count(s[i]) == 0){
                if(MySet.count(t[i]) > 0)
                    return false;
                MyMap[s[i]] = t[i];
                MySet.insert(t[i]);
            }else{
                s[i] = MyMap[s[i]];
                if(s[i]!=t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isIsomorphic("egg", "add")<<endl;
    return 0;
}