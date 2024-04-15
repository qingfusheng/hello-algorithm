class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        a = []
        s = s[::-1]
        temp = ""
        for ch in s:
            if not('a' <= ch <= 'z' or 'A' <= ch <= 'Z' or '0' <= ch <= '9'):
                continue
            ch = ch.upper()
            if len(temp) < k:
                temp = ch + temp
            else:
                a.append(temp)
                temp = "" + ch
        if len(temp) > 0:
            a.append(temp)
        return "-".join(reversed(a))