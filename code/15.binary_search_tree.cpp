#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	int height = 0;
	TreeNode(int value) :val(value), left(nullptr), right(nullptr), height(0) {};
};
class BinaryTree {
	TreeNode* root;
public:
	BinaryTree(vector<int>init_val) {
		root = nullptr;
		for (vector<int>::iterator it = init_val.begin(); it < init_val.end(); it++) {
			AddNode(*it);
		}
	}
	~BinaryTree() {
		clear(root);
	}
	void clear(TreeNode *root) {
		if (root == nullptr)
			return;
		clear(root->left);
		clear(root->right);
		delete root;
	}
	void AddNode(int val) {
		if (root == nullptr) {
			root = new TreeNode(val);
			root->height += 1;
			return;
		}
		TreeNode* tmp = root;
		while (tmp != nullptr) {
			if (val > tmp->val) {
				if (tmp->right == nullptr) {
					tmp->right = new TreeNode(val);
					break;
				}
				else {
					tmp = tmp->right;
				}
			}
			else if (val < tmp->val) {
				if (tmp->left == nullptr) {
					tmp->left = new TreeNode(val);
					break;
				}
				else {
					tmp = tmp->left;
				}
			}
			else {
				cout << "重复节点，已取消添加\n";
				break;
			}
		}
	}
	void remove(int num) {
		TreeNode* cur = root;
		TreeNode* pre = cur;
		if (cur == nullptr) {
			cout << "该二叉搜索树为空" << endl;
			return;
		}
		while (cur != nullptr) {
			if (num == cur->val)
				break;
			pre = cur;
			if (num < cur->val)
				cur = cur->left;
			else
				cur = cur->right;
		}
		if (cur == nullptr) {
			cout << "该二叉搜索树中无该节点" << endl;
			return;
		}
		if (cur->left == nullptr || cur->right == nullptr) {
			TreeNode* child = cur->left != nullptr ? cur->left : cur->right; // left||right||nullptr
			cout << cur->val << " " << root->val << endl;
			if (cur->val == root->val) {
				root = child;
				delete cur;
				return;
			}
			else {
				if (num > pre->val)
					pre->right = child;
				else
					pre->left = child;
			}
		}
		else {
			TreeNode* right_child = cur->right;
			TreeNode* left_cc = right_child->left;
			TreeNode* pre = right_child;
			if (left_cc == nullptr) {
				/*if (cur == root) {

				}*/
				TreeNode* tmp = cur;
				cout << "ROOT==CUR:";
				printf("%d\n", root == cur);
				cur->val = right_child->val;
				cur->right = right_child->right;
				//printf("\n%d\n", root == cur);
				delete right_child;
				return;
			}
			while (left_cc->left != nullptr) {
				pre = left_cc;
				left_cc = left_cc->left;
			}
			cur->val = left_cc->val;
			pre->left = left_cc->right;
			delete left_cc;
		}
	}
	void LevelTraverse() {
		cout << "层次遍历：";
		queue<TreeNode*>node_queues;
		node_queues.push(root);
		cout <<"ROOT:"<< root->val << endl;
		while (!node_queues.empty()) {
			TreeNode* tmp = node_queues.front();
			if (tmp == NULL) {
				cout << "N ";
				node_queues.pop();
				continue;
			}
			if (tmp->left != nullptr)
				node_queues.push(tmp->left);
			else
				node_queues.push(NULL);
			if (tmp->right != nullptr)
				node_queues.push(tmp->right);
			else
				node_queues.push(NULL);
			node_queues.pop();
			cout << tmp->val << " ";
		}
		cout << "\n";
	}
	void dfs(TreeNode* tmp, string params) {
		if (tmp == nullptr)return;
		if(params == "pre"){
			cout << tmp->val << " ";
		}
		dfs(tmp->left, params);
		if (params == "in") {
			cout << tmp->val << " ";
		}
		dfs(tmp->right, params);
		if (params == "post") {
			cout << tmp->val << " ";
		}
	}
	void XX_DFT() {
		cout << "先序遍历：";
		dfs(root, "pre");
		cout << "\n";
	}
	void ZX_DFT() {
		cout << "中序遍历：";
		dfs(root, "in");
		cout << "\n";
	}
	void HX_DFT() {
		cout << "后序遍历：";
		dfs(root, "post");
		cout << "\n";
	}
};
int main() {
	vector<int> demo = { 4,2,6,1,3,5,7 };
	BinaryTree tree = BinaryTree(demo);
	tree.LevelTraverse();
	tree.XX_DFT();
	tree.ZX_DFT();
	tree.HX_DFT();
	tree.remove(4);
	tree.LevelTraverse();
	tree.remove(5);
	tree.LevelTraverse();
}