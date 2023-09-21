#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void view_vector(vector<int> demo);
void view_vectorMatrix(vector<vector<int>> demo);
class GraphAdjMat {
private:
	vector<int> vertices;  // 顶点列表
	vector<vector<int>> adjMat;  // 邻接矩阵
public:
	GraphAdjMat(const vector<int>&vertices, const vector<vector<int>> &edges){
		// 因为这里是const常量所以不需要考虑修改问题，因此直接传入该元素而不是这个元素的副本，可以更有效的利用空间。
		for (const int& vertex : vertices)
			addVertex(vertex);
		for (const vector<int>& edge : edges)
			addEdge(edge[0], edge[1]);
	}
	// 这里的const仅供成员函数使用
	int size() const {
		return vertices.size();
	}
	void addVertex(int val) {
		int n = size();
		vertices.push_back(val);
		// 这两句的作用是加一行和加一列0元素
		adjMat.push_back(vector<int>(n, 0));
		// 这里row，而&row是调用原来的row，因此只用row并不会修改adjMat中的元素
		for (vector<int> &row : adjMat)
			row.push_back(0);
	}
	void addEdge(int i, int j) {
		if (i<0 || i>size() || j<0 || j>size() || i == j) {
			throw out_of_range("该顶点不存在");
		}
		adjMat[i][j] = 1;
		adjMat[j][i] = 1;
	}
	void removeEdge(int i, int j) {
		if (i<0 || i>size() || j<0 || j>size() || i == j) {
			throw out_of_range("该顶点不存在");
		}
		adjMat[i][j] = 0;
		adjMat[j][i] = 0;
	}
	void print() {
		cout << "顶点列表:\n";
		view_vector(vertices);
		cout << "邻接矩阵:\n";
		view_vectorMatrix(adjMat);
	}
};

void view_vector(vector<int> demo) {
	for (vector<int>::iterator it = demo.begin(); it < demo.end(); it++)
		cout << *it << " ";
	cout << endl;
}
void view_vectorMatrix(vector<vector<int>> demo) {
	for (vector<int> row : demo) {
		view_vector(row);
	}
}
int main() {
	vector<int> verties{0, 1, 2, 3, 4};
	vector<vector<int>> edges{ {1,2},{ 2,4} };
	GraphAdjMat graph = GraphAdjMat(verties, edges);
	graph.print();
}