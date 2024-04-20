
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num == 0:
            return '0'
        isPos = True
        if num < 0:
            isPos = False
        num = -1 * num if num < 0 else num
        a = []
        while num > 0:
            a.append(num % 7)
            num //= 7
        
        a = [str(_) for _ in a]
        if isPos:
            return "".join(a)[::-1]
        else:
            return "-"+"".join(a)[::-1]