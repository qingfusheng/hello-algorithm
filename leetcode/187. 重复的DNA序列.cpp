// 滑动窗口，但是实际上是一轮的遍历
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length() <= 10)return result;
        // 相比官解的HashMap解法，占用空间较小
        unordered_set<string> MySet;
        unordered_set<string> visited;
        
        for(int i=0; i <= s.length() - 10; i++){
            string temp(s.begin() + i, s.begin() + i + 10);
            if(MySet.find(temp) != MySet.end()){
                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    result.push_back(temp);
                }
            }else{
                MySet.insert(temp);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<string> result = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for(auto x: result){
        cout << x << endl;
    }
    return 0;
}

/*
// hashMap并不需要判断重复或者手动置值，直接++即可
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.length() <= 10)
            return result;
        unordered_map<string, int> MyMap;
        for(int i=0; i <= s.length() - 10; i++){
            string temp(s.begin() + i, s.begin() + i + 10);
            if(++MyMap[temp] == 2){
                result.push_back(temp);
            }
        }
        return result;
    }
};
*/