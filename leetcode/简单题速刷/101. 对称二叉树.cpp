#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
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
    bool isMirSim(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
			return true;
		}
        if (left == nullptr || right == nullptr) {
			return false;
		}
		return left->val == right->val && isMirSim(left->left, right->right) && isMirSim(left->right, right->left);
	}
public:
    bool isSymmetric(TreeNode* root) {
        return isMirSim(root->left, root->right);
    }
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    cout << s.isSymmetric(root) << endl;
}
