// 题目名称：102. 二叉树的层序遍历
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/description
// 题目思路：考虑层次遍历的高度

#include <iostream>
#include <vector>
#include <queue>
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>{};
        }
        queue<pair<TreeNode*, int>> nq;
        nq.push(pair<TreeNode*, int>(root, 1));
        vector<vector<int>> result{};
        vector<int> temp_vec{};
        int current_level = 1;
        while (!nq.empty()) {
            pair<TreeNode*, int> temp = nq.front();
            if (temp.second != current_level) {
                result.push_back(temp_vec);
                temp_vec.clear();
                current_level = temp.second;
            }
            temp_vec.push_back(temp.first->val);
            nq.pop();
            if(temp.first->left != nullptr){
                nq.push(pair<TreeNode*, int>(temp.first->left, temp.second+1));
            }
            if(temp.first->right != nullptr){
                nq.push(pair<TreeNode*, int>(temp.first->right, temp.second+1));
            }
        }
        if (temp_vec.size() > 0) {
            result.push_back(temp_vec);
        }
        return result;
    }
};
int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution s;
    vector<vector<int>> result = s.levelOrder(root);
    for(auto vec : result){
        for(auto val : vec){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}