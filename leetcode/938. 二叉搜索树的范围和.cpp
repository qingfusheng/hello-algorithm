// 题目名称：938. 二叉搜索树的范围和
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/range-sum-of-bst/description
// 题目思路：注意，二叉搜索树，DFS和BFS都可

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
 // 注意这是一个二叉搜索树
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr)
            return 0;
        if(root->val > high){
            // 不需要考虑该节点和该节点的右子树节点（均大于high），只需要考虑该节点的左子树节点
            return rangeSumBST(root->left, low, high);
        }
        if(root->val < low){
            // 以示例2中的节点5为例，5<6,而5->right>6,但是5->right->left == 6,所以当出现这种情况时，不需要考虑该节点和它的左子树节点，仅需要考虑右子树
            return rangeSumBST(root->right, low, high);
            }
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
/*
输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
输出：23
*/