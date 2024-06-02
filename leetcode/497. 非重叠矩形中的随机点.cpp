// 水塘抽样（也可以用前缀和+二分查找）
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> recs;
public:
    Solution(vector<vector<int>>& rects) {
        this->recs = rects;
    }
    
    vector<int> pick() {
        int index = 0, cur = 0, curSum = 0, n = recs.size();
        for(int i = 0; i < n; i++){
            int x1 = recs[i][0], y1 = recs[i][1], x2 = recs[i][2], y2 = recs[i][3];
            cur = (x2 - x1 + 1) * (y2 - y1 + 1);
            curSum += cur;  // 其中每个矩形区域的点被选择的概率与其面积成正比。
            if(rand() % curSum < cur){
                // 将这个随机整数映射到 [0, curSum-1] 的范围内。
                // rand() % curSum < cur 这部分用于决定当前的矩形 recs[i] 是否被选中：
                // 如果随机数落在 [0, curSum-1] 范围内的前 cur 个位置，则认为当前矩形被选中。
                // 由于 cur 是当前矩形的面积，而 curSum 是所有已处理矩形的总面积，这确保了每个矩形被选中的概率与其面积成正比。
                index = i;
            }
        }
        int x1 = recs[index][0], y1 = recs[index][1], x2 = recs[index][2], y2 = recs[index][3];
        return {x1 + rand() % (x2 - x1 + 1), y1 + rand() % (y2 - y1 + 1)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
int main(){
    
}

/*
水塘抽样算法
class Solution:

    def __init__(self, rects: List[List[int]]):
        self.recs = rects


    def pick(self) -> List[int]:
        curSum = 0
        index = 0
        for i, (x1, y1, x2, y2) in enumerate(self.recs):
            cur = (x2 - x1 + 1) * (y2 - y1 + 1)
            curSum += cur
            if random.randint(0, curSum - 1) < cur:
                index = i 
        x1, y1, x2, y2 = self.recs[index]
        return [random.randint(x1, x2), random.randint(y1, y2)]


# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
*/

/*
前缀和+二分方法：
class Solution {
private:
    vector<vector<int>> rects;
    vector<int> preS;
public:
    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        preS.push_back(0);
        for(auto& rec : rects)
        {
            int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
            preS.push_back(preS.back() + (x2-x1+1) * (y2-y1+1));
        }
    }
    
    vector<int> pick() {
        int w = rand() % preS.back() + 1;
        int l = 0, r = preS.size()-1;
        while(l < r)
        {
            int mid = (l+r) >> 1;
            if(preS[mid] < w)
                l = mid+1;
            else
                r = mid;
        }
        --l;
        int x1 = rects[l][0], y1 = rects[l][1], x2 = rects[l][2], y2 = rects[l][3];
        return {x1 + rand()%(x2-x1+1), y1 + rand()%(y2-y1+1)};
    }
};

作者：小虎
链接：https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/solutions/1543128/shui-tang-chou-yang-by-xiaohu9527-7b3d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/