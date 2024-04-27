# hash表，py的re和lower方便一些
from typing import List
import re
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        data = {}
        reg = re.compile(r'[a-zA-Z]+')
        words = reg.findall(paragraph)
        for word in words:
            if word.lower() in banned:
                continue
            word = word.lower()
            if word not in data:
                data[word]  = 1
            else:
                data[word] += 1
        
        max_freq = 0
        max_freq_string = ""


        for key, value in data.items():
            if value > max_freq:
                max_freq = value
                max_freq_string = key
        return max_freq_string
        
