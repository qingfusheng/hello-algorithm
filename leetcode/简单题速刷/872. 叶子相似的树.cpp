// 注意这里只能用深度优先搜索，广搜会乱序
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
    void dfs(TreeNode* root, vector<int>& container){
        if(root->left == nullptr && root->right == nullptr){
            container.push_back(root->val);
        }
        if(root->left != nullptr)dfs(root->left, container);
        if(root->right != nullptr)dfs(root->right, container);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> container1;
        vector<int> container2;
        dfs(root1, container1);
        dfs(root2, container2);
        if(container1.size() != container2.size())return false;
        for(int i=0;i<container1.size();i++){
            if(container1[i] != container2[i])return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->right->left = new TreeNode(9);
    root1->right->right = new TreeNode(8);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(6);
    root2->left->right = new TreeNode(7);
    root2->right->left = new TreeNode(4);
    root2->right->right = new TreeNode(2);
    root2->right->right->left = new TreeNode(9);
    root2->right->right->right = new TreeNode(8);
    cout << s.leafSimilar(root1, root2) << endl;
    return 0;
}