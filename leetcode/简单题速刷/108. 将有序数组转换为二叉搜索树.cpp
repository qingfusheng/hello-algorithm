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
public:
    void raversal(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node == nullptr) {
                cout << "null" << " ";
                continue;
            }
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return AddTreeNode(nums, 0, nums.size() - 1);
    }
    TreeNode* AddTreeNode(vector<int>& nums, int left, int right) {
        int mid = left + (right - left + 1) / 2;
        if (left > right)  // 当left > right时，说明已经没有节点了，返回nullptr
            return nullptr;
        if(left == right)  // 当left == right时，说明只有一个节点了，返回这个节点
            return new TreeNode(nums[left]);
        TreeNode* root = new TreeNode(nums[mid]);  // 选择中间节点作为根节点
        root->left = AddTreeNode(nums, left, mid - 1);  // 递归构建左子树
        root->right = AddTreeNode(nums, mid + 1, right);  // 递归构建右子树
        return root;
    }
};

int main() {
    Solution s;
    vector<int> nums{ -10,-3,0,5,9 };
    TreeNode * root = s.sortedArrayToBST(nums);
    s.raversal(root);
}
