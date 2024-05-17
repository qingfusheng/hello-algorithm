# 题目名称：826. 安排工作以达到最大收益
# 题目来源：LeetCode
# 题目难度：中等
# 题目链接：https://leetcode.cn/problems/most-profit-assigning-work/description
# 题目思路：排序+双指针

class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        res = i = best = 0
        worker.sort()
        for w in worker:
            while i < len(jobs) and w >= jobs[i][0]:
                best = max(best, jobs[i][1])
                i += 1
            res += best
        return res
    

""" 
class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        MyList = [[difficulty[index], profit[index], difficulty[index] / profit[index]] for index in
                  range(len(difficulty))]
        MyList.sort(key=lambda x: [-x[2], x[0]])
        worker.sort()
        index1 = 0
        index2 = 0
        result = 0

"""