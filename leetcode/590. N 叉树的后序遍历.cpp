// 题目名称：590. N 叉树的后序遍历
// 题目来源：LeetCode
// 题目难度：简单
// 题目链接：https://leetcode.cn/problems/n-ary-tree-postorder-traversal/description
// 题目思路：后序遍历，深度优先搜索，左右中

#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
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
    void back_order(Node *root){
        if(root == nullptr)
            return;
        for(auto child_node: root->children){
            back_order(child_node);
        }
        result.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        back_order(root);
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
    vector<int> result = s.postorder(root);
    for(auto val: result){
        cout << val << " ";
    }
    cout << endl;
}