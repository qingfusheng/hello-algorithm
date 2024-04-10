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
    vector<string> result;
    void backtrack(TreeNode *root, string path){
        if(root== nullptr)return;
        path += to_string(root->val);
        if(root->left ==nullptr && root->right == nullptr){
            result.push_back(path);
        }else{
            path += "->";
            backtrack(root->left, path);
            backtrack(root->right, path);
        }
    }
public:
    // 回溯
    vector<string> binaryTreePaths(TreeNode* root) {
        backtrack(root, "");
        return result;
    }
};

int main(){

}