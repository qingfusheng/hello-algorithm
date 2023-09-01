#include<iostream>
#include<vector>
using namespace std;
/* 数组表示下的二叉树类 */
class ArrayBinaryTree {
public:
    /* 构造方法 */
    ArrayBinaryTree(vector<int> arr) {
        tree = arr;
    }

    /* 节点数量 */
    int size() {
        return tree.size();
    }

    /* 获取索引为 i 节点的值 */
    int val(int i) {
        // 若索引越界，则返回 INT_MAX ，代表空位
        if (i < 0 || i >= size())
            return INT_MAX;
        return tree[i];
    }
    /* 获取索引为 i 节点的左子节点的索引 */
    int left(int i) {
        return 2 * i + 1;
    }
    /* 获取索引为 i 节点的右子节点的索引 */
    int right(int i) {
        return 2 * i + 2;
    }
    /* 获取索引为 i 节点的父节点的索引 */
    int parent(int i) {
        return (i - 1) / 2;
    }

    /* 层序遍历 */
    vector<int> levelOrder() {
        vector<int> res;
        // 直接遍历数组
        for (int i = 0; i < size(); i++) {
            if (val(i) != INT_MAX)
                res.push_back(val(i));
        }
        return res;
    }

    /* 前序遍历 */
    vector<int> preOrder() {
        vector<int> res;
        dfs(0, "pre", res);
        return res;
    }

    /* 中序遍历 */
    vector<int> inOrder() {
        vector<int> res;
        dfs(0, "in", res);
        return res;
    }

    /* 后序遍历 */
    vector<int> postOrder() {
        vector<int> res;
        dfs(0, "post", res);
        return res;
    }

private:
    vector<int> tree;

    /* 深度优先遍历 */
    void dfs(int i, string order, vector<int>& res) {
        // 若为空位，则返回
        if (val(i) == INT_MAX)
            return;
        // 前序遍历
        if (order == "pre")
            res.push_back(val(i));
        dfs(left(i), order, res);
        // 中序遍历
        if (order == "in")
            res.push_back(val(i));
        dfs(right(i), order, res);
        // 后序遍历
        if (order == "post")
            res.push_back(val(i));
    }
};
void ViewVector(vector<int> the_array) {
    for (vector<int>::iterator it = the_array.begin(); it < the_array.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
int main(int args, char *argv) {
    vector<int> demo = { 1,2,3,4,5,6,7 };
    ArrayBinaryTree tree =  ArrayBinaryTree(demo);
    //ArrayBinaryTree *tree = new ArrayBinaryTree(demo);
    vector<int> result;
    result = tree.levelOrder();
    ViewVector(result);
    result = tree.preOrder();
    ViewVector(result);
    result = tree.inOrder();
    ViewVector(result);
    result = tree.postOrder();
    ViewVector(result);
    cout << tree.size() << endl;
    return 0;
}