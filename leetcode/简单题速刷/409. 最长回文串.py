# dict比unordered_map好写

class Solution:
    def longestPalindrome(self, s: str) -> int:
        if len(s) == 1:
            return 1
        s_dict = {}
        for ch in s:
            if ch not in s_dict:
                s_dict[ch] = 1
            else:
                s_dict[ch] += 1
        hasOdd = False
        sum = 0
        for key, value in s_dict.items():
            if not hasOdd:
                if value % 2 != 0:
                    hasOdd = True
            if value % 2 == 1:
                value -= 1
            sum += value
        if hasOdd:
            sum += 1
        return sum