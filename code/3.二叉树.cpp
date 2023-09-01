#include<iostream>
using namespace std;
#define nullptr NULL 

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : value(0), left(nullptr), right(nullptr) {};
	TreeNode(int val) : value(val), left(nullptr), right(nullptr) {};
};
int arr[15] = {};
void Init() {
	for (int i = 0; i < 15; i++)
		arr[i] = i + 1;
}
TreeNode* buildbinaryTree(int n, int left, int right) {
	if (n == 0)
		return nullptr;
	int mid = (left + right + 1) / 2;
	TreeNode* root = new TreeNode(arr[mid]);
	root->left = buildbinaryTree(n - 1, left, mid - 1);
	root->right = buildbinaryTree(n - 1, mid + 1, right);
	return root;
}
void xx(TreeNode* root) {
    if (root == nullptr)
        return;
    xx(root->left);
    cout << root->value << endl;
    xx(root->right);

}
void zx(TreeNode* root) {
    if (root == nullptr)
        return;
    cout << root->value << endl;
    zx(root->left);
    zx(root->right);
}
void hx(TreeNode* root) {
    if (root == nullptr)
        return;
    hx(root->left);
    hx(root->right);
    cout << root->value << endl;
}

int main(int argc, char *args[]) {
	Init();
	TreeNode *tree = buildbinaryTree(4, 0, sizeof(arr) / sizeof(arr[0])-1);
	cout << "先序遍历：" << endl;
	xx(tree);
	cout << "中序遍历：" << endl;
	zx(tree);
	cout << "后序遍历：" << endl;
	hx(tree);
//	cout<<"遍历结束"<<endl;
}
