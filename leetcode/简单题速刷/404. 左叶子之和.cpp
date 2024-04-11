/*深度优先搜索，不过在dfs的参数中加入了一个标志左右节点的bool变量，使其在左叶节点的情况下进行Sum求和*/
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
    int LeftSum = 0;
    void dfs(TreeNode *root, bool Childleft){
        if(Childleft && (root->left == nullptr && root->right == nullptr))
            LeftSum+=root->val;
        if(root->left != nullptr)
            dfs(root->left, true);
        if(root->right != nullptr)
            dfs(root->right, false);
    }
private:

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)return 0;
        if(root->left == nullptr && root->right == nullptr) return 0;
        dfs(root, false);
        return LeftSum;
    }
};

int main(){

}
