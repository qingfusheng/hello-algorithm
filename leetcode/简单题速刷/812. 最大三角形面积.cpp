// 纯枚举的方法，时间复杂度O(n^3)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        return 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    }

    double largestTriangleArea(vector<vector<int>> & points) {
        int n = points.size();
        double ret = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    ret = max(ret, triangleArea(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]));
                }
            }
        }
        return ret;
    }
};
int main(){
    Solution s;
    vector<vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    cout << s.largestTriangleArea(points) << endl;
    return 0;
}