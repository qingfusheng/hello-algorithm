// 题目名称：1600. 王位继承顺序
// 题目来源：LeetCode
// 题目难度：中等
// 题目链接：https://leetcode.cn/problems/throne-inheritance/description/
// 题目思路：多叉树的先序遍历，使用哈希表存储节点（不过额外借用了TreeNode结构）

#include<iostream>
#include<vector>
#include<queue>
#include <unordered_map>
#include<string>
using namespace std;

class KingNode {
public:
    string name;
    bool isAlive = true;
    vector<KingNode*> children{};
    KingNode(string name) {
        this->name = name;
    }
};

class ThroneInheritance {
private:
    unordered_map<string, KingNode*> NameMap;
    vector<string> res;
    KingNode* king;
    void dfs(KingNode* root) {
        if (root->isAlive) {
            res.push_back(root->name);
		}
        for (int i = 0; i < root->children.size(); i++) {
			dfs(root->children[i]);
		}
    }
public:
    ThroneInheritance(string kingName) {
        king = new KingNode(kingName);
        NameMap[kingName] = king;
    }

    void birth(string parentName, string childName) {
        KingNode* child = new KingNode(childName);
        NameMap[parentName]->children.push_back(child);
        NameMap[childName] = child;
    }

    void death(string name) {
        NameMap[name]->isAlive = false;
    }

    vector<string> getInheritanceOrder() {
        res.clear();
        dfs(king);
        return res;
    }
};


int main() {
 //   // ["ThroneInheritance", "birth", "birth", "birth", "birth", "birth", "birth", "getInheritanceOrder", "death", "getInheritanceOrder"]
 //   // [["king"], ["king", "andy"], ["king", "bob"], ["king", "catherine"], ["andy", "matthew"], ["bob", "alex"], ["bob", "asha"], [null], ["bob"], [null]]
 //   ThroneInheritance* obj = new ThroneInheritance("king");
 //   obj->birth("king", "andy");
 //   obj->birth("king", "bob");
 //   obj->birth("king", "catherine");
 //   obj->birth("andy", "matthew");
 //   obj->birth("bob", "alex");
 //   obj->birth("bob", "asha");
 //   vector<string> param_3 = obj->getInheritanceOrder();
 //   // view param_3
 //   for (int i = 0; i < param_3.size(); i++) {
	//	cout << param_3[i] << " ";
	//}
 //   cout << endl;

 //   obj->death("bob");
 //   vector<string> param_4 = obj->getInheritanceOrder();
 //   for (int i = 0; i < param_4.size(); i++) {
 //       cout << param_4[i] << " ";
 //   }
 //   cout << endl;
    ThroneInheritance* obj = new ThroneInheritance("rurik");
    obj->birth("rurik", "igor");
    vector<string> result;
    result = obj->getInheritanceOrder();
    for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
}
