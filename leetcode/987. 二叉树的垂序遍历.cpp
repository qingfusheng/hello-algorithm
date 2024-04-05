// 题目名称：987. 二叉树的垂序遍历
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/description
// 题目思路：二叉树的中序遍历，同时记录每个节点的数值、垂直坐标以及高度。根据这几个值进行排序，最后按照垂直坐标输出结果
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
    vector<vector<int>> result;
    vector<pair<int, pair<int, int>>> plain_result;
    void dfs(pair<TreeNode*, pair<int, int>>temp) {
        if (temp.first == nullptr)
            return;
        dfs(pair<TreeNode*, pair<int, int>>(temp.first->left, pair<int, int>(temp.second.first - 1, temp.second.second + 1)));
        plain_result.push_back(pair<int, pair<int, int>>(temp.first->val, pair<int, int>(temp.second.first, temp.second.second)));
        dfs(pair<TreeNode*, pair<int, int>>(temp.first->right, pair<int, int>(temp.second.first + 1, temp.second.second + 1)));
    }
    static bool PairCompare(const std::pair<int, pair<int, int>> &a, const std::pair<int, pair<int, int>> &b) {
        if (a.second.first == b.second.first) {
            if (a.second.second == b.second.second) {
                return a.first < b.first;
            }
            return a.second.second < b.second.second;
        }
        return a.second.first < b.second.first;
	}
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(pair<TreeNode*, pair<int, int>>(root, pair<int, int>(0, 0)));
        sort(plain_result.begin(), plain_result.end(), PairCompare);
        for(auto each : plain_result)
			cout << each.first << " " << each.second.first << " " << each.second.second << endl;
        int current = plain_result[0].second.first;
        vector<int> temp;
        for (auto each : plain_result) {
            if (each.second.first == current) {
                temp.push_back(each.first);
            }
            else {
                result.push_back(temp);
                temp.clear();
                temp.push_back(each.first);
                current = each.second.first;
            }
        }
        if (!temp.empty())
			result.push_back(temp);
        return result;
    }
};
int main() {
    // root = [3,1,4,0,2,2]
    // 首先看垂直坐标，然后看高度，最后看数值
    TreeNode* node0 = new TreeNode(3);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(0);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node5 = new TreeNode(2);
    node0->left = node1;
    node0->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    Solution s;
    vector<vector<int>> result = s.verticalTraversal(node0);
    for (auto each : result) {
        for (auto each2 : each) {
			cout << each2 << " ";
		}
		cout << endl;
	}
}