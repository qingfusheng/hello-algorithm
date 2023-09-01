#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) :val(value), left(nullptr),right(nullptr) {};
};
// 广度优先遍历
void BFS(TreeNode* root) {
	TreeNode* tmp = root;
	queue<TreeNode*> node_queue;
	node_queue.push(root);
	while (node_queue.size() != 0) {
		TreeNode* tmp = node_queue.front();
		if (tmp->left != nullptr)
			node_queue.push(tmp->left);
		if (tmp->right != nullptr)
			node_queue.push(tmp->right);
		cout << node_queue.front()->val << " ";
		node_queue.pop();
	}
	cout << endl;
}
//深度优先遍历（先序F，中序M，后序B
void DFS_F(TreeNode* root) {
	// 根-左-右
	if (root == nullptr)
		return;
	cout << root->val << " ";
	DFS_F(root->left);
	DFS_F(root->right);
}
void DFS_M(TreeNode* root) {
	if (root == nullptr)
		return;
	DFS_M(root->left);
	cout << root->val << " ";
	DFS_M(root->right);
}
void DFS_B(TreeNode* root) {
	if (root == nullptr)
		return;
	DFS_B(root->left);
	DFS_B(root->right);
	cout << root->val << " ";
}
int main() {
	TreeNode* n1 = new TreeNode(4);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(6);
	TreeNode* n4 = new TreeNode(1);
	TreeNode* n5 = new TreeNode(3);
	TreeNode* n6 = new TreeNode(5);
	TreeNode* n7 = new TreeNode(7);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	cout << "广度优先搜索：";
	BFS(n1);
	cout << "深搜之先序遍历：";
	DFS_F(n1);
	cout << endl;
	cout << "深搜之中序遍历：";
	DFS_M(n1);
	cout << endl;
	cout << "深搜之后序遍历：";
	DFS_B(n1);
	cout << endl;
}