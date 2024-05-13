// 题目名称：994. 腐烂的橘子
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/rotting-oranges/description
// 题目思路：广度优先搜索，跟前面传染那个很相似，不过这个是二维列表
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> pq;
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    sum++;
                if (grid[i][j] == 2) {
                    pq.push(pair<int, int>(i, j));
                }
            }
        }
        int count = 0;
        while (sum > 0 && !pq.empty()) {
            int length = pq.size();
            count++;
            for (int i = 0; i < length; i++) {
                int x = pq.front().first;
                int y = pq.front().second;
                if (x + 1 < m && grid[x + 1][y] == 1) {
                    grid[x + 1][y] = 2;
                    sum--;
                    pq.push(pair<int, int>(x + 1, y));
                }
                if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                    grid[x - 1][y] = 2;
                    sum--;
                    pq.push(pair<int, int>(x - 1, y));
                }
                if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                    grid[x][y - 1] = 2;
                    sum--; 
                    pq.push(pair<int, int>(x, y - 1));
                }
                if (y + 1 < n && grid[x][y + 1] == 1) {
                    grid[x][y + 1] = 2;
                    sum--;
                    pq.push(pair<int, int>(x, y + 1));
                }
                // 如果没有sum > 0 的条件，此处也可以设置一个标志位，只要有一个1被改为2，就将这个标志位设为true，只有true的时候count才会加一，表示被感染
                pq.pop();
            }
        }
        return sum != 0 ? -1 : count;
    }
};

int main() {
    /*vector<vector<int>> grid = { {2,1,1},{1,1,0},{0,1,1} };*/
    vector<vector<int>> grid = { {2,1,1},{0,1,1},{1,0,1} };
	Solution s;
	cout << s.orangesRotting(grid) << endl;
	return 0;
}
