// 思路很简单，就是判断每个节点的左右深度和的最大值，还有，请分清height和depth的区别
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

// 这样代码更简洁，可读性高，但是，需要注意的是，遍历树的时候，从叶节点结束还是从空结束会影响程序的效率，前者更快一点，但代码更麻烦一点
class Solution {
private:
    int max_dist = INT_MIN;
    int getDepth(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        max_dist = max(max_dist, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return max_dist;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << s.diameterOfBinaryTree(root) << endl;
    return 0;

}


/*
// 实际上是有问题的，我应该判断它是叶节点还是它是空，还有，那个叫depth，不叫height
class Solution {
private:
    int max_dist = INT_MIN;
    int getMaxHeight(TreeNode *root){
        if(root->left == nullptr && root->right == nullptr){
            cout<<"root->val:"<<root->val<<", root->height:"<<1<<endl;
            return 1;
        }
        int left = 0, right = 0;
        if(root->left != nullptr)
            left = getMaxHeight(root->left);
        if(root->right != nullptr)
            right = getMaxHeight(root->right);
        max_dist = max(max_dist, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)return 0;
        getMaxHeight(root);
        return max_dist;
    }
};
*/