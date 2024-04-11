# 双绿，还是py更友好
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        a_dict = {}
        for ch in s:
            if ch in a_dict:
                a_dict[ch] += 1
            else:
                a_dict[ch] = 1
        for ch in t:
            if ch in a_dict:
                a_dict[ch] -= 1
            else:
                return ch
        for key, value in a_dict.items():
            if value < 0:
                return key



""" 
C++版本：排序加双指针
class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int index1 = 0, index2 = 0;
        while(index1 < s.length() && index2 < t.length()){
            if(s[index1] != t[index2])
                return t[index2];
            else{
                index1++, index2++;
            }
        }
        return t[t.length() - 1];
    }
};
"""