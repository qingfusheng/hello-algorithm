// 题目名称：589. N 叉树的前序遍历
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/n-ary-tree-preorder-traversal/description
// 题目思路：后序遍历，深度优先搜索，左右中
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution { 
private:
    vector<int> result;
    void pre_order(Node *root){
        if(root == nullptr)
            return;
        result.push_back(root->val);
        for(auto child_node: root->children){
            pre_order(child_node);
        }
        
    }
public:
    vector<int> preorder(Node* root) {
        pre_order(root);
        return result;
    }
};
int main(){
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node3 = new Node(3, {node5, node6});
    Node *node2 = new Node(2);
    Node *node4 = new Node(4);
    Node *root = new Node(1, {node3, node2, node4});
    Solution s;
    vector<int> result = s.preorder(root);
    for(auto val: result){
        cout << val << " ";
    }
    cout << endl;
}