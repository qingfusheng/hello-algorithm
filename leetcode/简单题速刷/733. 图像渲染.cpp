#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    void fill(int val, vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>> &visited) {
        image[sr][sc] = color;
        visited[sr][sc] = 1;

        if (sr + 1 < image.size() && image[sr + 1][sc] == val && !visited[sr + 1][sc]) {
            fill(val, image, sr + 1, sc, color, visited);
        }
        if (sr - 1 >= 0 && image[sr - 1][sc] == val && !visited[sr - 1][sc]) {
            fill(val, image, sr - 1, sc, color, visited);
        }
        if (sc + 1 < image[0].size() && image[sr][sc + 1] == val && !visited[sr][sc+1]) {
            fill(val, image, sr, sc + 1, color, visited);
        }
        if (sc - 1 >= 0 && image[sr][sc - 1] == val && !visited[sr][sc-1]) {
            fill(val, image, sr, sc - 1, color, visited);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        fill(image[sr][sc], image, sr, sc, color, visited);
        return image;
    }
};
int main() {
    Solution s;
	vector<vector<int>> image = { {1,1,1},{1,1,0},{1,0,1} };
	vector<vector<int>> res = s.floodFill(image, 1, 1, 2);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;   

}