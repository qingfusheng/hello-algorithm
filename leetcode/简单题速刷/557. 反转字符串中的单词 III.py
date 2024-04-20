# 用python，一行代码解决
# 为什么不用C++，因为没有split
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join([each[::-1] for each in s.split(" ")])
    


"""
// 别急，C++也有
class Solution {
public:
    string reverseWords(string s) {
        string result;
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i] != ' '){
                temp.push_back(s[i]);
            }else{
                reverse(temp.begin(), temp.end());
                result += temp + ' ';
                temp.clear();
            }
        }
        reverse(temp.begin(), temp.end());
        result += temp;
        return result;
    }
};
"""