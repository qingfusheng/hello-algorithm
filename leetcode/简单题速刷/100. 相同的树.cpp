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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
			return true;
        if (p == nullptr || q == nullptr)
            return false;
        queue<TreeNode* > pq, qq;
        pq.push(p);
        qq.push(q);
        vector<int> pv, qv;
        while (true) {
            if (pq.empty() || qq.empty()) {
                if (pq.empty() && qq.empty()) {
                    return true;
                }
                else {
                    return false;
                }
            }
            TreeNode* root1 = pq.front();
            TreeNode* root2 = qq.front();
            pq.pop();
            qq.pop();
            if (root1->val != root2->val)
                return false;
            if (root1->left != nullptr && root2->left != nullptr) {
                pq.push(root1->left);
                qq.push(root2->left);
            }
            else if (root1->left == nullptr && root2->left == nullptr)
                printf("");
            else
                return false;
            if (root1->right != nullptr && root2->right != nullptr) {
                pq.push(root1->right);
                qq.push(root2->right);
            }
            else if (root1->right == nullptr && root2->right == nullptr)
                printf("");
            else
                return false;
        }
        return true;
    }
};


int main() {
    Solution s;
    TreeNode* p = new TreeNode(1);
    TreeNode* q = new TreeNode(1);
    q->right = new TreeNode(2);
    cout << s.isSameTree(p, q);

    return 0;
}
