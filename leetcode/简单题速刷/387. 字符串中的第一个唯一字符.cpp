#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
// 以一种很笨的方法
    int firstUniqChar(string s) {
        reverse(s.begin(), s.end());
        unordered_map<char, pair<int, int>> MyMap;
        for(int i=0;i<s.length();i++){
            cout<<s[i]<<" ";
            if(MyMap.find(s[i]) != MyMap.end()){
                cout<<"Repeating"<<endl;
                MyMap[s[i]].first = i;
                MyMap[s[i]].second += 1;
            }else{
                cout<<"Creating"<<endl;
                MyMap.insert({s[i], pair<int, int>(i, 1)});
            }
        }
        for(auto kv: MyMap){
            if(kv.second.second == 1){
                return s.length() - kv.second.first - 1;
            }
        }
        return -1;
    }
};
int main(){

}


/*
// 还不如直接遍历两遍
class Solution {
public:
    int firstUniqChar(string s) {
        int a[26] = {0};
        for(char ch: s)
            a[ch-'a'] += 1;
        for(int i = 0;i<s.length();i++){
            if(a[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};
*/