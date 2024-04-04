# 题目名称：2192. 有向无环图中一个节点的所有祖先
# 题目来源：LeetCode
# 题目难度：中等 * 
# 题目链接：https://leetcode.cn/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/description/
# 题目思路：深度优先搜索，邻接字典
# 备注：如何优雅的获取所有的parent（因为py内置的dict方便一些，所以就直接用py了，会有点超时严重

from typing import List, Dict


class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        # 构建邻接字典
        adj_dict: Dict[int, List[int]] = {i: [] for i in range(n)}
        for (parent, child) in edges:
            adj_dict[child].append(parent)

        # 构建结果列表
        result = [[] for _ in range(n)]
        for child in range(n):
            # 使用深度优先搜索找到所有祖先
            stack = adj_dict[child][:]  # 首先获取直接父节点
            # 如果存在父节点，那么就继续向上搜索
            while stack:
                parent = stack.pop()  # 从栈中弹出一个节点
                # 如果该节点不在结果列表中，那么就添加到结果列表中
                if parent not in result[child]:
                    result[child].append(parent)
                    stack.extend(adj_dict[parent])
        return [sorted(ans) for ans in result]


if __name__ == '__main__':
    n = 10
    edges = [[5, 2], [8, 7], [7, 2], [8, 3], [1, 6], [9, 0]]
    s = Solution()
    print(s.getAncestors(n, edges))
