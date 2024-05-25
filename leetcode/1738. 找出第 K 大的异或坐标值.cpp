// 题目名称：1738. 找出第 K 大的异或坐标值
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/find-kth-largest-xor-coordinate-value/description/
// 题目思路：前缀和+排序，优先队列
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> results(m*n);
        int index = 0;
        vector<vector<int>> Vec(matrix.begin(), matrix.end());
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0)Vec[i][j] = Vec[i][j] ^ Vec[i-1][j];
                if(j>0)Vec[i][j] = Vec[i][j] ^ Vec[i][j-1];
                if(i>0 && j>0) Vec[i][j] = Vec[i][j] ^ Vec[i-1][j-1];
                results[index++] = Vec[i][j];
            }
        }
        nth_element(results.begin(), results.begin() + k - 1, results.end(), greater<int>());
        return results[k-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{5,2},{1,6}};
    int k = 1;
    cout << s.kthLargestValue(matrix, k) << endl;
    return 0;
}

/*
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        std::priority_queue<int> pq;
        vector<vector<int>> Vec(matrix.size(), vector<int>(matrix[0].size()));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                Vec[i][j] = matrix[i][j];
                if(i>0)Vec[i][j] = Vec[i][j] ^ Vec[i-1][j];
                if(j>0)Vec[i][j] = Vec[i][j] ^ Vec[i][j-1];
                if(i>0 && j>0) Vec[i][j] = Vec[i][j] ^ Vec[i-1][j-1];
                pq.push(Vec[i][j]);
            }
        }
        while(--k>0){
            pq.pop();
        }
        return pq.top();
    }
};
*/