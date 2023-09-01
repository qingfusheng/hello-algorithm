#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void view_vector(vector<T>& v) {
	cout << "该vector的长度为：" << v.size() << "\n该vector的值为：[";
	int integer = 1;
	int character = 'c';
	for (int i = 0; i < v.size(); i++) {
		if (std::is_same<T, int>::value)
			cout << v[i];
		else if (std::is_same<T, char>::value)
			cout << "'" << v[i] << "'";
		else cout << v[i];
		if (i < v.size() - 1)
			cout << ", ";
	}
	cout << "]\n";
}

int main() {
	// vector的构建方法
	// 构建一个空的vector
	vector <int> T1;
	view_vector(T1);
	// 构建n个值为val的vector
	vector <int>T2(20, 2);
	view_vector(T2);
	vector<int> T2_1(20);
	view_vector(T2_1);
	/*for (int i = 0; i < 10; i++)
		T1.push_back(i + 1);*/
	vector <int>T3(T2_1.begin(), T2_1.end());
	view_vector(T3);
	string s = "hello world";
	vector<char> T4(s.begin(), s.end());
	view_vector(T4);
	vector <char>T5(T4);
	view_vector(T5);
	cout << "T4和T5的值是否相同：" << ((T4 == T5) ? "True" : "False") << endl;
	cout << "T4和T5的地址是否相同：" << ((&T4 == &T5) ? "True" : "False") << endl;

	// vector的遍历
	// 方法1（下标遍历法）
	for (int i = 0; i < T5.size(); i++) {
		cout << T5.at(i) << ", ";
		//cout << T5[i] << ", ";
	}
	cout << endl;
	// 方法2（迭代遍历法）

	for (vector<char>::iterator it = T5.begin(); it < T5.end(); it++) // it != T5.end()
	{
		cout << *it << ", "; //这里的it是地址。
	}
	cout << endl;
	// 方法3（迭代2
	printf("第三种迭代方法\n");
	for (char n : T5)
		cout << n << ", ";
	cout << endl;
	vector <int> T(5, 2);
	view_vector(T);
	T.clear();
	view_vector(T);
	for (int i = 0; i < 10; i++)
		T.push_back(i + 1);
	view_vector(T);
	T[0] = 10;
	view_vector(T);
	T.at(0) = 1;
	view_vector(T);
	T.erase(T.begin() + 2);
	view_vector(T);
	T.insert(T.begin() + 2, 3);
	view_vector(T);
	T.erase(T.begin() + 4, T.begin() + 6);
	view_vector(T);
	T.pop_back(); // pop_back()不返回任何内容
	view_vector(T);
	int a[2][2] = { 1,2,3,4 };
	vector<int*>TN;
	for (int i = 0; i < 2; i++)
		TN.push_back(a[i]);  // 这里push进去的是a[0]和a[1]的地址。
	view_vector(TN);
	for (vector<int*>::iterator it = TN.begin(); it < TN.end(); it++) {
		for (int i = 0; i < 2; i++) {
			cout << **it + i << " ";
		}
		cout << endl;
	}
}
