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
    int max_height = 0;
    int length = 0;
    void dfs(TreeNode *root, int height){
        max_height = max(max_height, height);
        if(root->left == nullptr && root->right == nullptr){
            if(height == max_height)
                length += 1;
            else
                return;
        }
        if(root->left != nullptr)
            dfs(root->left, height + 1);
        if(root->right != nullptr)
            dfs(root->right, height + 1);
    }
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root, 0);
        cout<<max_height<<", "<<length<<endl;
        return (1 << max_height) -1 + length;
    }
};

int main(){

}


/*
我感觉用深搜做没毛病，但是我需要将树的高度和叶子结点的数目存下来，我只需要搜到第一个不是最大高度的叶子结点就直接返回就可以了，
这样的话，就相当于是深搜的优化版本吧，不好评价复杂度，如果遇到一个满二叉树就会到O(n)，而最理想的情况就是只有最高level只有一个叶节点，
这样复杂度就是变成O(log2n),当然应该还能再优化，比如判断左和右分别判断叶节点的height。

*/