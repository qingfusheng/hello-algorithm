#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
		if (rec1[1] >= rec2[3] || rec1[2] <= rec2[0] || rec1[3] <= rec2[1] || rec1[0] >= rec2[2])
            return false;
		else 
            return true;
	}
};

int main(){
    Solution s;
    vector<int> rec1 = {0,0,2,2};
    vector<int> rec2 = {1,1,3,3};
    cout << s.isRectangleOverlap(rec1, rec2) << endl;
    return 0;
}

/*
题解：https://leetcode.cn/problems/rectangle-overlap/solutions/2759081/li-yong-bu-zhong-die-lai-pan-duan-zhong-acjuu/
*/