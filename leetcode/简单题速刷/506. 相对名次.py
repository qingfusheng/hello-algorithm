from typing import List

class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        dec = ("Gold Medal", "Silver Medal", "Bronze Medal")
        score_list = sorted(enumerate(score), key=lambda x: x[1], reverse=True)
        result = ["" for _ in range(len(score))]
        for index in range(len(score)):
            if index <= 2:
                result[score_list[index][0]] = dec[index]
            else:
                result[score_list[index][0]] = str(index + 1)
        return result