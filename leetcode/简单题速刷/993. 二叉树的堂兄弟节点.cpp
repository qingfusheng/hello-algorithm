#include<iostream>
#include<vector>
#include<queue>
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
    int x;
    int y;
    int depthX = -1, depthY = -1;
    int parentX = -1, parentY = -1;
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            if (root->left->val == x) {
                parentX = root->val;
                depthX = depth + 1;
            }
            if (root->left->val == y) {
                parentY = root->val;
                depthY = depth + 1;
            }
        }
        if (root->right != nullptr) {
            if (root->right->val == x) {
                parentX = root->val;
                depthX = depth + 1;
            }
            if (root->right->val == y) {
                parentY = root->val;
                depthY = depth + 1;
            }
        }
        if (depthX != -1 && depthY != -1) return;
        if (root->left != nullptr) dfs(root->left, depth + 1);
        if (root->right != nullptr) dfs(root->right, depth + 1);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        queue<pair<TreeNode*, int>> pq;
        dfs(root, 0);
        cout<<depthX<<" "<<depthY<<" "<<parentX<<" "<<parentY<<endl;
        return depthX == depthY && parentX != parentY;
    }
};

int main() {
    Solution s;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	cout << s.isCousins(root, 3, 4) << endl;
	return 0;
}