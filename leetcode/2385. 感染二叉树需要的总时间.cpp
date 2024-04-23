// 题目名称：2385. 感染二叉树需要的总时间
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/amount-of-time-for-binary-tree-to-be-infected/description/
// 题目思路：有点笨的方法，但是胜在比较好理解，先遍历一遍树（这里用的是层级遍历），然后对树间关系建立一个双向映射，并创建一个set()用来存所有的节点。然后针对于这个set()进行处理：另创建一个queue(),这个队列用于存储每过1min被感染的元素，感染以后就将该元素从set中除去，这是一个循环，最后直到所有的元素都被感染就可以了。
#include<iostream>
#include<vector>
#include<unordered_map>
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
    int amountOfTime(TreeNode* root, int start) {
        unordered_set<int> available_node;
        unordered_map<int, vector<int>> MyMap;
        queue<TreeNode*> pq;
        pq.push(root);
        available_node.insert(root->val);
        while (!pq.empty()) {
            TreeNode* cur = pq.front();
            pq.pop();
            if (cur->left != nullptr) {
                available_node.insert(cur->left->val);
                pq.push(cur->left);
                MyMap[cur->val].push_back(cur->left->val);
                MyMap[cur->left->val].push_back(cur->val);
            }
            if (cur->right != nullptr) {
                available_node.insert(cur->right->val);
                pq.push(cur->right);
                MyMap[cur->val].push_back(cur->right->val);
                MyMap[cur->right->val].push_back(cur->val);
            }
        }

        int time = 0;
        queue<int> pq2;
        pq2.push(start);
        available_node.erase(start);
        while (!available_node.empty()) {
            int size = pq2.size();
            for (int i = 0; i < size; i++) {
				int cur = pq2.front();
				pq2.pop();
                for (auto& elem : MyMap[cur]) {
                    if (available_node.find(elem) != available_node.end()) {
						pq2.push(elem);
						available_node.erase(elem);
					}
				}
			}
            time += 1;
        }
        return time;

    }
};
int main() {
    TreeNode* root = new TreeNode(19);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(9);
    root->left->right = new TreeNode(11);
    root->right->left = new TreeNode(18);
    root->right->right = new TreeNode(1);
    root->left->right->right = new TreeNode(17);
    root->right->left->right = new TreeNode(8);
    root->right->left->right->right = new TreeNode(20);
    Solution sol;
    cout << sol.amountOfTime(root, 1) << endl;
    return 0;
}