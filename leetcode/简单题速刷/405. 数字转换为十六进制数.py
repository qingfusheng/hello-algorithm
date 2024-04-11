# 405. 数字转换为十六进制数
class Solution:
    def toHex(self, num: int) -> str:
        if num >= 0:
            return str(hex(num))[2:]
        else:
            return str(hex(num + 0xFFFFFFFF + 1))[2:]