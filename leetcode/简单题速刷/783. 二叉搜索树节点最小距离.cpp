// 注意：本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同
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
    int min_dist = INT_MAX;
    bool setted = false;
    int pre;
    void dfs(TreeNode *root){
        if(root->left != nullptr)
            dfs(root->left);
        
        if(setted){
            min_dist = min(min_dist, root->val - pre);    
        }else{
            setted = true;
        }
        pre = root->val;

        if(root->right != nullptr)
            dfs(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return min_dist;
    }
};