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
    int sum = 0;
    void dfs(TreeNode *root, int val){
        if(root->left == nullptr && root->right == nullptr){
            sum += val;
            return;
        }
        if(root->left != nullptr)
            dfs(root->left, (val << 1) + root->left->val);
        if(root->right != nullptr)
            dfs(root->right, (val << 1) + root->right->val);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, root->val);
        return sum;
    }
};

int main(){
    Solution s = Solution();
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    cout << s.sumRootToLeaf(root) << endl;
    return 0;
}