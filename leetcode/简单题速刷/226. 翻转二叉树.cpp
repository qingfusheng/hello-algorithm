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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode *temp = root->right;  // 因为right会被修改，所以需要暂存
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        return root;
    }
};

int main(){

}

/*
跟官方题解很相似，反转左右子树，然后返回根节点即可
*/