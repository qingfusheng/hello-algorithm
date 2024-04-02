// 题目名称：1379. 找出克隆二叉树中的相同节点
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/description
// 题目思路：广度优先遍历或者深度优先遍历（先序、中序、后序）
#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        // 广度优先，层次遍历
        queue<TreeNode *> node_queue;
        node_queue.push(cloned);
        while (node_queue.size() != 0)
        {
            TreeNode *tmp = node_queue.front();
            if (tmp->val == target->val)
            {
                return tmp;
            }
            if (tmp->left != nullptr)
                node_queue.push(tmp->left);
            if (tmp->right != nullptr)
                node_queue.push(tmp->right);
            cout << node_queue.front()->val << " ";
            node_queue.pop();
        }
        return target;
    }
};
int main(){
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(6);
    TreeNode *n4 = new TreeNode(1);
    TreeNode *n5 = new TreeNode(3);
    TreeNode *n6 = new TreeNode(5);
    TreeNode *n7 = new TreeNode(7);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;
    Solution solu = Solution();
    TreeNode *res = solu.getTargetCopy(n1, n1, n3);
    cout << res->val << endl;
    return 0;
}


/*
// 深搜，递归，相对来讲时间更短一些
class Solution {
    TreeNode *res = new TreeNode();
public:
    void process(TreeNode *root, int val){
        if(root == nullptr)
            return;
        if(root->val == val){
            res = root;
            return;
        }
        process(root->left, val);
        process(root->right, val);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        process(cloned, target->val);
        return res;
    }
};
*/