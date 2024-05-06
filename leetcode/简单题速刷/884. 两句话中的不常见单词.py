from typing import List

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        a = {}
        s = s1 + " " + s2
        for word in s.split(" "):
            if word in a:
                a[word] += 1
            else:
                a[word] = 1
        result = []
        for key, value in a.items():
            if value == 1:
                result.append(key)
        return result