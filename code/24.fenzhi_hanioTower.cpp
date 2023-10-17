#include<iostream>
#include<vector>
using namespace std;
int the_count = 0;
// 使用结构体来标记柱子（虽然柱子并不叫bullet，但是不要在意这些细节啦^o^
struct TheBullet {
	string b_name;
	vector<int> b_value;
	TheBullet(string name, vector<int>& value) {
		b_name = name;
		b_value = value;
	}
	void push_back(int temp) {
		b_value.push_back(temp);
	}
	void pop_back() {
		b_value.pop_back();
	}
	int back() {
		return b_value.back();
	}
	int size() {
		return b_value.size();
	}
	void view() {
		cout << b_name << ":";
		for (vector<int>::iterator it = b_value.begin(); it < b_value.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
};
void move(TheBullet& src, TheBullet& tar) {
	the_count += 1;
	// 有没有不那么冗杂的方法来标记src和target的name
	// cout << "move from " << src.b_name << " to " << tar.b_name << endl;
	int temp = src.back();
	src.pop_back();
	tar.push_back(temp);
	return;
}
void dfs(int n, TheBullet& src, TheBullet& buf, TheBullet& tar) {
	if (n == 1) {
		move(src, tar);
		return;
	}
	dfs(n - 1, src, tar, buf);
	move(src, tar);
	dfs(n - 1, buf, src, tar);
}
void solveHanio(TheBullet& A, TheBullet& B, TheBullet&C) {
	int n = A.size();
	dfs(n, A, B, C);
}

void view_vector(string vector_name, vector<int>& demo) {
	cout << vector_name << ":";
	for (vector<int>::iterator it = demo.begin(); it < demo.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main() {
	int num = 10;
	vector<int> A(num, 0);
	vector<int> B;
	vector<int> C;
	for (int i = 0; i < num; i++)
		A[i] = num - i;
	TheBullet Ab = TheBullet("A", A);
	TheBullet Bb = TheBullet("B", B);
	TheBullet Cb = TheBullet("C", C);
	solveHanio(Ab, Bb, Cb);
	cout << "总移动次数为" << the_count << endl;
	Ab.view();
	Bb.view();
	Cb.view();
}