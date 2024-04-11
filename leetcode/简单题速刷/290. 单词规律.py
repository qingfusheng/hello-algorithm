# dict比unordered_map好写，所以写py

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        s_list = s.split(" ")
        if len(pattern) != len(s_list):
            return False
        s_dict = {}
        for i in range(len(pattern)):
            if pattern[i] not in s_dict:
                if s_list[i] not in s_dict.values():
                    s_dict[pattern[i]] = s_list[i]
                else:
                    return False
            else:
                if s_dict[pattern[i]] != s_list[i]:
                    return False
                else:
                    continue
        return True