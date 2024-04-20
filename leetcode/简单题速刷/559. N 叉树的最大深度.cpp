#include <bits/stdc++.h>
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
    int maxDepth(Node* root) {
        if(root == nullptr){
            return 0;
        }
        int maxD = 0;
        for(Node *child: root->children){
            maxD = max(maxD, maxDepth(child));
        }
        return maxD + 1;
    }
};

int main(){
    Solution s;
    Node *root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    cout << s.maxDepth(root) << endl;
    return 0;
}

/*
    遍历我还是会写的。
    因为这里是多个child，因此判断哪个节点是不是空会好些一点。（接543题——二叉树的直径）
*/