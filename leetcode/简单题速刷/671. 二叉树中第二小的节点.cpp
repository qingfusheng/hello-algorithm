// 面向测试用例编程
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

class Solution {
private:
    int min1 = INT_MAX, min2 = INT_MAX;
    bool has_INTMAX = false;
    void dfs(TreeNode *root){
        int temp = root->val;
        if(temp == INT_MAX)has_INTMAX = true;
        if(temp < min1){
            min2 = min1;
            min1 = temp;
        }
        if(temp < min2 && temp != min1){
            min2 = temp;
        }
        if(temp > min2){
            return;
        }
        if(root->left != nullptr)
            dfs(root->left);
        if(root->right != nullptr)
            dfs(root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if(has_INTMAX){
            if(min1 == INT_MAX && min2 == INT_MAX)return -1;
            else return min2;
        };
        return min2 == INT_MAX ? -1 :min2;
    }
};