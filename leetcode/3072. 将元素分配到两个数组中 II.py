# 若使用C++则需要借助树结构
from typing import List
from sortedcontainers import SortedList


class Solution:
    def resultArray(self, nums: List[int]) -> List[int]:
        arr1, arr2 = SortedList(), SortedList()
        a, b = [], []
        arr1.add(nums[0])
        a.append(nums[0])
        arr2.add(nums[1])
        b.append(nums[1])
        for i in range(2, len(nums)):
            num = nums[i]
            l = len(arr1) - bisect_right(arr1, num)
            r = len(arr2) - bisect_right(arr2, num)
            if l > r or l == r and len(arr1) < len(arr2):
                arr1.add(num)
                a.append(num)
            elif l < r or l == r and len(arr1) > len(arr2):
                arr2.add(num)
                b.append(num)
            else:
                arr1.add(num)
                a.append(num)

        return a + b