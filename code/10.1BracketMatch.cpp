#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
char s_list[3][2] = { {'{', '}'},{'[',']'},{'(', ')'} };
std::unordered_map<char, char> matching = {
		{')', '('},
		{']', '['},
		{'}', '{'}
};
bool BracketMatch(string ss) {
	stack<char> stack;
	bool matched = true;
	for (int i = 0; i < ss.size(); i++) {
		for (int j = 0; j < 3; j++) {
			if (s_list[j][0] == ss[i])
				stack.push(ss[i]);
			if (s_list[j][1] == ss[i])
				if (!stack.empty() && stack.top() == s_list[j][0])
					stack.pop();
				else
					matched = false;
		}
	}
	if (!stack.empty())
		matched = false;
	return matched;
}
bool BracketMatch2(string ss) {
	std::stack<char> stk;
	for (char c : ss) {
		if (c == '(' || c == '[' || c == '{') {
			stk.push(c);
		}
		else if (c == ')' || c == ']' || c == '}') {
			if (stk.empty() || !matching[c]==stk.top()) {
				return false;
			}
			stk.pop();
		}
	}
	return stk.empty();
}
int main() {
	string ss;
	cin >> ss;
	string result = BracketMatch2(ss) ? "Yes" : "No";
	cout << "括号是否成功匹配：" << result << endl;
}