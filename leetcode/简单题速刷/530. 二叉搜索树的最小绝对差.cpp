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
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return min_dist;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    cout << s.getMinimumDifference(root) << endl;
    return 0;
}

/*
// 因为是二叉搜索树，所以 left < root < right, 因此使用中序遍历（有序），只需要比较相邻的两个节点的差值即可。
*/