// 题目名称：429. N 叉树的层序遍历
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description
// 题目思路：中序遍历，层次遍历的高度

#include<iostream>
#include<vector>
#include<queue>
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
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return vector<vector<int>>{};
        }
        queue<pair<Node*, int>> nq;
        nq.push(pair<Node*, int>(root, 1));
        vector<vector<int>> result{};
        vector<int> temp_vec{};
        int current_level = 1;
        while (!nq.empty()) {
            pair<Node*, int> temp = nq.front();
            if (temp.second != current_level) {
                result.push_back(temp_vec);
                temp_vec.clear();
                current_level = temp.second;
            }
            temp_vec.push_back(temp.first->val);
            nq.pop();
            for (auto node : temp.first->children) {
                if (node != nullptr) {
                    nq.push(pair<Node*, int>(node, temp.second+1));
                }
            }
        }
        if (temp_vec.size() > 0) {
            result.push_back(temp_vec);
        }
        return result;
    }
};
int main() {
    // [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
    // special_example: []
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);
    Node* node10 = new Node(10);
    Node* node11 = new Node(11);
    Node* node12 = new Node(12);
    Node* node13 = new Node(13);
    Node* node14 = new Node(14);
    root->children.push_back(node2);
    root->children.push_back(node3);
    root->children.push_back(node4);
    root->children.push_back(node5);
    node3->children.push_back(node6);
    node3->children.push_back(node7);
    node4->children.push_back(node8);
    node4->children.push_back(node9);
    node4->children.push_back(node10);
    node8->children.push_back(node11);
    node8->children.push_back(node12);
    node9->children.push_back(node13);
    node13->children.push_back(node14);
    Solution s;
    vector<vector<int>> result = s.levelOrder(root);
    for (auto val : result) {
        for (auto val2 : val) {
            cout << val2 << ", ";
        }
        cout << endl;
    }
    cout << endl;
}