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
    int max_height = 1;
    void dfs(TreeNode *root, int length){
        if(length > max_height)
            max_height = length;
        if(root->left != nullptr)
            dfs(root->left, length + 1);
        if(root->right != nullptr)
            dfs(root->right, length + 1);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        dfs(root, 1);
        return max_height;
    }
};
int main(){
    
}

/*
// 官方题解
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
*/