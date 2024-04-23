#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<int, int>> MyVec;
        queue<pair<TreeNode*, int>> pq;
        vector<double> result;
        if (root == nullptr)
            return result;
        pq.push(pair<TreeNode*, int>(root, 0));
        while (!pq.empty()) {
            pair<TreeNode*, int> cur = pq.front();
            MyVec.push_back(pair<int, int>(cur.first->val, cur.second));
            pq.pop();
            if (cur.first->left != nullptr)
                pq.push(pair<TreeNode*, int>(cur.first->left, cur.second + 1));
            if (cur.first->right != nullptr)
                pq.push(pair<TreeNode*, int>(cur.first->right, cur.second + 1));
        }
        int cur_val = 0;
        double temp = 0;
        int count = 0;
        for (auto& each : MyVec) {
            if (each.second == cur_val) {
                temp += each.first;
                count++;
            }
            else {
                cur_val = each.second;
                result.push_back(temp / count);
                temp = each.first;
                count = 1;
            }
        }
        result.push_back(temp / count);
        return result;
    }
};
int main() {
    TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	Solution s;
	vector<double> res = s.averageOfLevels(root);
    for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}

/*
* // 层次遍历的另一种方法，不需要额外的height标记，只需要每次都将queue清空，即每一层的所有元素
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        auto averages = vector<double>();
        auto q = queue<TreeNode*>();
        q.push(root);
        while (!q.empty()) {
            double sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                sum += node->val;
                auto left = node->left, right = node->right;
                if (left != nullptr) {
                    q.push(left);
                }
                if (right != nullptr) {
                    q.push(right);
                }
            }
            averages.push_back(sum / size);
        }
        return averages;
    }
};
*/