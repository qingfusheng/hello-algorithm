// 题目名称：1026. 节点与其祖先之间的最大差值
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/description/
// 题目思路：深度优先搜索
// 备注：深度优先搜索，重要的是维护 maxVal和minVal，而不是最开始想的维护局部的距离最大值
#include<iostream>
#include<algorithm>
#include<string>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int max_distance = 0;
    void dfs(TreeNode* root, int maxVal, int minVal) {
        
        if (root == nullptr) {
            return;
        }
        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);
        max_distance = max(max_distance, (maxVal - minVal));
        dfs(root->left, maxVal, minVal);
        dfs(root->right, maxVal, minVal);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MIN, INT_MAX);
        return max_distance;
    }
};

int main() {
    // root = [8,3,10,1,6,null,14,null,null,4,7,13]
    TreeNode *root = new TreeNode(8);
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(10);
    TreeNode *node3 = new TreeNode(1);
    TreeNode *node4 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(14);
    TreeNode *node6 = new TreeNode(4);
    TreeNode *node7 = new TreeNode(7);
    TreeNode *node8 = new TreeNode(13);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;
    node4->left = node6;
    node4->right = node7;
    node5->left = node8;
    Solution sol;
    int result = sol.maxAncestorDiff(root);
    cout << result << endl;

}