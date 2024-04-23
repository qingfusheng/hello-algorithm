#include <iostream>
#include <vector>
#include <unordered_set>
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
    bool matched = false;
    unordered_set<int> MySet;
    void dfs(TreeNode *root, int k){
        MySet.insert(root->val);
        if(k - root->val != root->val&&MySet.find(k - root->val)!=MySet.end()){
            matched = true;
            return;
        }
        if(root->left != nullptr)
            dfs(root->left, k);
        if(root->right != nullptr)
            dfs(root->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root, k);
        return matched;
    }
};

/*
官方题解：
class Solution {
public:
    unordered_set<int> hashTable;

    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr) {
            return false;
        }
        if (hashTable.count(k - root->val)) {
            return true;
        }
        hashTable.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

*/