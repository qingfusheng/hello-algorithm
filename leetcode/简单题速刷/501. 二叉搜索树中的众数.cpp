#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 没有考虑二叉搜索树的特征
class Solution {
private:
    unordered_map<int, int> MyMap;
    void dfs(TreeNode* root){
        int temp = root->val;
        if(MyMap.find(temp) == MyMap.end()){
            MyMap[temp] = 1;
        }else{
            MyMap[temp] ++;
        }

        if(root->left != nullptr)
            dfs(root->left);
        if(root->right != nullptr)
            dfs(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        dfs(root);
        int max_val = INT_MIN;
        for(auto &kv: MyMap){
            if(kv.second > max_val){
                max_val = kv.second;
            }
        }
        for(auto &kv: MyMap){
            if(kv.second == max_val){
                result.push_back(kv.first);
            }
        }
        return result;
    }
};

int main(){

}

/*
    简单题并不简单系列
class Solution {
public:
    vector<int> answer;
    int base, count, maxCount;

    void update(int x) {
        if (x == base) {
            ++count;
        } else {
            count = 1;
            base = x;
        }
        if (count == maxCount) {
            answer.push_back(base);
        }
        if (count > maxCount) {
            maxCount = count;
            answer = vector<int> {base};
        }
    }

    void dfs(TreeNode* o) {
        if (!o) {
            return;
        }
        dfs(o->left);
        update(o->val);
        dfs(o->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return answer;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/find-mode-in-binary-search-tree/solutions/425430/er-cha-sou-suo-shu-zhong-de-zhong-shu-by-leetcode-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/