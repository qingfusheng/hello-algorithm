// 题目名称：1146. 快照数组
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/snapshot-array/description/
// 题目思路：
// 备注：二分查找
#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
public:
    vector<vector<pair<int, int>>> nums; // first is snap id; second is value
    int snap_num;
    SnapshotArray(int length) {
        nums.resize(length, {{0, 0}});
        snap_num = 0;
    }
    
    void set(int index, int val) {
        if(nums[index].size() == 0 || nums[index].back().first != snap_num) {
            nums[index].push_back({snap_num, val});
        } else{
            nums[index].back().second = val;
        }
    }
    
    int snap() {
        snap_num++;
        return snap_num-1;
    }
    
    int get(int index, int snap_id) {
        snap_id++;
        int l = 0, r = nums[index].size()-1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[index][mid].first < snap_id) {
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return nums[index][l-1].second;
    }
};

int main() {
    SnapshotArray* obj = new SnapshotArray(3);
	obj->set(0, 5);
	obj->snap();
	obj->set(0, 6);
	cout << obj->get(0, 0) << endl;
	return 0;
}