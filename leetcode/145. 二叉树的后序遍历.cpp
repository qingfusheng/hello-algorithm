// 题目名称：145. 二叉树的后序遍历
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
// 题目思路：后序遍历
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> result;
    void dfs(TreeNode *root){
        if(root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        result.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return result;
    }
};

int main(){
    
}