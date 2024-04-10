#include <bits/stdc++.h>
using namespace std;

// 排序很简单，但是很慢
class Solution{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int n = s.length();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        //  return s==t;只需要判断字符串是否相等即可
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[i])
                continue;
            else
                return false;
        }
        return true;
    }
};

int main()
{
}

/*
// 哈希表unordered_map，似乎比上一个方法更慢，占用空间更多
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())return false;
        unordered_map<char, int> MyMap;
        for(char ch: s){
            if(MyMap.find(ch) != MyMap.end()){
                MyMap[ch] += 1;
            }else{
                MyMap[ch] = 1;
            }
        }
        for(char ch: t){
            if(MyMap.find(ch) != MyMap.end()){
                MyMap[ch] -= 1;
            }else{
                return false;
            }
        }
        for(auto kv: MyMap){
            if(kv.second != 0)
                return false;
        }
        return true;
    }
};
*/

/*
因为题目规定是只有小写字母，所以只需要用一个长度为26的数组存储每个字母出现的次数即可（最快最小）
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int a[26];
        memset(a, 0, 26);
        for(int i = 0;i<s.length(); i++){
            a[s[i] - 'a'] += 1;
        }
        for(int i=0;i<t.length();i++){
            a[t[i] - 'a'] -= 1;
            if(a[t[i] - 'a'] < 0)return false;
        }
        for(int i=0;i<26;i++)
            if(a[i] != 0)
                return false;
        return true;
    }
};
*/