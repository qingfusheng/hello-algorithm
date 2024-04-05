# 题目名称：2129. 将标题首字母大写
# 题目来源：LeetCode
# 题目难度：简单
# 题目链接：https://leetcode.cn/problems/capitalize-the-title/description/
# 题目思路：py很好做，C++还要考虑空格和长度的问题，还有upper和lower

class Solution:
    def capitalizeTitle(self, title: str) -> str:
        str_list = title.split(" ")
        s = ""
        for each_index in range(len(str_list)):
            each = str_list[each_index]
            if len(each) <= 2:
                s += each.lower()
            else:
                s += each[0].upper() + each[1:].lower()
            if each_index < len(str_list) - 1:
                s+=" " 
        return s

if __name__ == '__main__':
    s = Solution()
    print(s.capitalizeTitle("capiTalIze tHe titLe")) # The Code Signal
    print(s.capitalizeTitle("an hello world")) # An Hello World
    print(s.capitalizeTitle("a")) # a
    