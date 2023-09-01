#include<iostream>
#include<unordered_map>
using namespace std;
void view_map(unordered_map<int, string>map) {
	cout << "<<<预览哈希表开始***\n";
	// kv.first表示key，kv.second表示value
	for (auto kv : map) {
		cout << kv.first << ": " << kv.second << endl;
	}
	cout << "***预览哈希表结束>>>\n";
	return;
}
int main() {
	/* 初始化哈希表 */
	unordered_map<int, string> map;

	/* 添加操作 */
	// 在哈希表中添加键值对 (key, value)
	map[12836] = "小哈";
	map[15937] = "小啰";
	map[16750] = "小算";
	map[13276] = "小法";
	map[10583] = "小鸭";
	view_map(map);
	/* 查询操作 */
	// 向哈希表输入键 key ，得到值 value
	string name = map[15937];
	cout << "学号为15937的学生的姓名：" << name << endl;
	/* 删除操作 */
	// 在哈希表中删除键值对 (key, value)
	map.erase(10583);
	view_map(map);
	return 0;
}