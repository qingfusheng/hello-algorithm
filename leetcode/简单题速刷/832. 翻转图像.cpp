#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i = 0;i<n;i++){
            reverse(image[i].begin(), image[i].end());
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                image[i][j] = !image[i][j];
            }
        }
        return image;
    }
};
int main(){
    Solution s;
    vector<vector<int>> image = {{1,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> result = s.flipAndInvertImage(image);
    for(int i = 0;i<result.size();i++){
        for(int j = 0;j<result[i].size();j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
普通方法，使用C++内置的reverse函数
*/