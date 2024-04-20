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
    bool isSub = false;
    bool isSameTree(TreeNode* root1, TreeNode* root2){
        cout<<"checking:"<<root1->val<<", "<<root2->val<<endl;
        if(root1->val != root2->val)
            return false;
        bool verify1 = true, verify2 = true;
        if(root1->left != nullptr &&root2->left != nullptr){
            verify1 = isSameTree(root1->left, root2->left);
        }else if((root1->left == nullptr &&root2->left != nullptr) || (root1->left != nullptr && root2->left == nullptr)){
            verify1 = false;
            return false;
        }else if(root1->left == nullptr && root2->left == nullptr){
            verify1 = true;
        }

        if(root1->right != nullptr && root2->right != nullptr){
            verify2 = isSameTree(root1->right, root2->right);
        }else if((root1->right == nullptr &&root2->right != nullptr) || (root1->right != nullptr && root2->right == nullptr)){
            verify2 = false;
            return false;
        }else{
            verify2 = true;
        }
        return verify1 && verify2;
    }
    void dfs(TreeNode *root, TreeNode *subRoot){
        if(isSameTree(root, subRoot)){
            cout<<"Root:"<<root->val<<endl;
            isSub = true;
            return;
        }else{
            if(root->left != nullptr)
                dfs(root->left, subRoot);
            if(root->right != nullptr)
                dfs(root->right, subRoot);
        }
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        dfs(root, subRoot);
        return isSub;
    }
};