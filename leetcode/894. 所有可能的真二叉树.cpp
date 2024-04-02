// 题目名称：894. 所有可能的真二叉树
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/all-possible-full-binary-trees/description/
// 题目思路：链表，（分治或递归），满二叉树
// 备注：当前方法为分治（递归），不是很掌握这部分
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
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
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> fullBinaryTrees;
        if (n % 2 == 0) {
            // 满二叉树的节点数必为奇数，因此返回空vector
            return fullBinaryTrees;
        }
        if (n == 1) {
            fullBinaryTrees = { new TreeNode(0) };
            return fullBinaryTrees;
        }
        for (int i = 1; i < n; i += 2) {
            // 递归构造左右子树
            vector<TreeNode*> leftSubtrees = allPossibleFBT(i);
            vector<TreeNode*> rightSubtrees = allPossibleFBT(n - 1 - i);
            for (TreeNode* leftSubtree : leftSubtrees) {
                for (TreeNode* rightSubtree : rightSubtrees) {
                    TreeNode* root = new TreeNode(0, leftSubtree, rightSubtree);
                    fullBinaryTrees.emplace_back(root);
                }
            }
        }
        return fullBinaryTrees;
    }
};


int main() {
    Solution solu = Solution();
    int n = 7;
    vector<TreeNode*> result = solu.allPossibleFBT(n);
    // view the TreeNode vector
    int count = 0;
    for (TreeNode* root : result) {
        // view(root);
        count += 1;
	}
}