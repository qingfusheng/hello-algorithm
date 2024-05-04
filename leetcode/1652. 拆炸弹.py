"""
    原则上用滑动窗口或者前缀和，但是这个题目的数据量很小，所以直接暴力解决
"""

from typing import List

class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        code += code
        result = [0] * n
        if k > 0:
            left =  1
            right = k + 1
        elif k < 0:
            left = n + k
            right = n
        else:
            return result
        
        for i in range(0, n):
            sum = 0
            for j in range(left + i, right + i):
                sum += code[j]
            result[i] = sum

        return result
