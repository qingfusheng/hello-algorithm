// 题目名称：1483. 树节点的第 K 个祖先
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/description
// 题目思路：倍增法Binary Lifting，递推公式：ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1]
// 备注：

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 倍增法
class TreeAncestor {
private:
    vector<vector<int>> ancestors;
    constexpr static int Log = 16;
public:
    TreeAncestor(int n, vector<int>& parent) {
        ancestors = vector<vector<int>>(n, vector<int>(Log, -1));
        // ancestors[i][j]指i节点的第2^j个祖先，这里的递归公式是：ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1]
        // 即，i的第2^j个祖先，就是（i的第2^(j-1)个祖先）的第2^(j-1)个祖先【加起来】，就像
        for (int i = 0; i < n; i++) {
            ancestors[i][0] = parent[i];
        }
        for (int j = 1; j < Log; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestors[i][j - 1] != -1) {
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < Log; j++) {
            if (k >> j & 1) {
                node = ancestors[node][j];
                if (node == -1)
                    return -1;
            }
        }
    }
};

int main() {
    vector<int> parent = { -1, 0, 0, 1, 1, 2, 2 };
	TreeAncestor* obj = new TreeAncestor(7, parent);
	cout << obj->getKthAncestor(3, 1) << endl;
	cout << obj->getKthAncestor(5, 2) << endl;
	cout << obj->getKthAncestor(6, 3) << endl;
	return 0;
}
/*
// 暴力，自然会超时
class TreeAncestor {
private:
    vector<vector<int>> dp;
    vector<int> parent;
public:
    TreeAncestor(int n, vector<int>& parent) {
        this->parent = parent;
    }

    int getKthAncestor(int node, int k) {
        if (k == 0) {
            return node;
        }
        if (this->parent[node] == -1) {
            return -1;
        }
        else {
            return getKthAncestor(this->parent[node], k-1);
        }
    }
};
*/