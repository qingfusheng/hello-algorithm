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
    int PDSum = 0;
    int LRSum(TreeNode *root){
        if(root == nullptr)
            return 0;
        int left = LRSum(root->left);
        int right = LRSum(root->right);
        int dist = left >= right ? left-right : right-left;
        PDSum += dist;
        return root->val + left + right;
    }
public:
    int findTilt(TreeNode* root) {
        LRSum(root);
        return PDSum;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << s.findTilt(root) << endl;
    return 0;
}