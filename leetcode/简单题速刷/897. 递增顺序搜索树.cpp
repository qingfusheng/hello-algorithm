#include<bits/stdc++.h>
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
    void dfs(TreeNode *root, vector<int>& res){
        if(root->left != nullptr)dfs(root->left, res);
        res.push_back(root->val);
        if(root->right != nullptr) dfs(root->right, res);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        TreeNode *head = new TreeNode(0);
        TreeNode *cur = head;
        for(int val: res){
            TreeNode *temp = new TreeNode(val);
            cur->right = temp;
            cur = cur->right;
        }
        return head->right;
    }
};

int main(){

}

/*
    应该可以在空间复杂度为O(1)的情况下解决
*/