// BFS, DFS, 回溯，栈
#include<iostream>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }
        //注意递归的写法
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {
    // [5,4,8,11,null,13,4,7,2,null,null,null,1]
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    // [-2, -3]
    Solution sol;
    cout <<"result:" << sol.hasPathSum(root, -5) << endl;
    return 0;
}

/*
class Solution {
private:
    bool isTrue = false;
    bool count = 0;
    void dfs(TreeNode* root, int length, int targetSum) {
        cout <<"count:" << count++ << endl;
        if (root == nullptr) {
            cout << "nullptr" << endl;
            return;
        }
        cout << root->val << ", " << length << endl;
        if (length == targetSum && (root->left == nullptr && root->right == nullptr)) {
            isTrue = true;
            return;
        }
        if (root->left)
            dfs(root->left, length + root->left->val, targetSum);
        if (root->right)
            dfs(root->right, length + root->right->val, targetSum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        dfs(root, 0 + root->val, targetSum);
        return isTrue;
    }
};
*/