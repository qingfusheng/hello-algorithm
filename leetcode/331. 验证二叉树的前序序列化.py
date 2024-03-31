# 题目名称：331. 验证二叉树的前序序列化
# 题目来源：LeetCode
# 题目难度：中等
# 题目链接：https://leetcode.cn/problems/verify-preorder-serialization-of-a-binary-tree/description
# 题目思路：字符串，栈
# 备注：不想用C++做了（实际上是字符串转列表不想写了，就直接用py做了，反正后面那个循环的意思是，检测到 1##这种样式就将其替换为#，直到栈里只剩下一个#

import queue
class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        order_list = preorder.split(",")
        j_count = 0
        for each_order in order_list:
            if each_order == '#':
                j_count += 1
        if len(order_list) - j_count + 1 != j_count:
            return False
        stack = queue.LifoQueue()
        for each_order in order_list:
            stack.put(each_order)
            while stack.qsize() >= 3:
                temp3 = stack.get()
                temp2 = stack.get()
                if temp2 == '#' and temp3 == '#':
                    stack.get()
                    stack.put('#')
                    continue
                else:
                    stack.put(temp2)
                    stack.put(temp3)
                    break
        if stack.qsize() == 1 and stack.get() == '#':
            return True
        else:
            return False