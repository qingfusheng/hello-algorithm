#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct Vertex;
void view_vector(vector<Vertex*> demo);
struct Vertex {
	// 该顶点结构体只用于存储节点的value（为什么不直接用int呢
	int val;
	Vertex(int x) : val(x) {
	}
};

/* 输入值列表 vals ，返回顶点列表 vets */
vector<Vertex*> valsToVets(vector<int> vals) {
	vector<Vertex*> vets;
	for (int val : vals) {
		vets.push_back(new Vertex(val));
	}
	return vets;
}

/* 输入顶点列表 vets ，返回值列表 vals */
vector<int> vetsToVals(vector<Vertex*> vets) {
	vector<int> vals;
	for (Vertex* vet : vets) {
		vals.push_back(vet->val);
	}
	return vals;
}
class GraphAdjList {
public:
	// 邻接表（存的是节点与该节点邻接的节点<为什么不存储索引呢>
	unordered_map<Vertex*, vector<Vertex*>> adjList;
	GraphAdjList(const vector<vector<Vertex*>>& edges) {
		for (const vector<Vertex*>& edge : edges) {
			addVertex(edge[0]);
			addVertex(edge[1]);
			addEdge(edge[0], edge[1]);
		}
	}
	~GraphAdjList() {
		// hapmap标准库不需要手动释放内存
	}
	int size() {
		return adjList.size();
	}
	void addEdge(Vertex* vet1, Vertex* vet2) {
		if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2) {
			throw invalid_argument("顶点不存在");
		}
		adjList[vet1].push_back(vet2);
		adjList[vet2].push_back(vet1);
	}
	void addVertex(Vertex* vet) {
		if (adjList.count(vet))
			return;
		adjList[vet] = vector<Vertex*>();
	}
	void removeEdge(Vertex* vet1, Vertex* vet2) {
		if (!adjList.count(vet1) || !adjList.count(vet2) || vet1 == vet2)
			throw invalid_argument("顶点不存在");
		remove(adjList[vet1], vet2);
		remove(adjList[vet2], vet1);
	}
	void removeVertex(Vertex* vet) {
		if (!adjList.count(vet))
			throw invalid_argument("顶点不存在");
		adjList.erase(vet);
		for (auto& adj : adjList) {
			remove(adj.second, vet);
		}
	}

	// 在vector中删除指定节点
	void remove(vector<Vertex*>& vec, Vertex* vet) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == vet) {
				vec.erase(vec.begin() + i);
				break;
			}
		}
	}
	void print() {
		cout << "邻接表：" << endl;
		for (auto& adj : adjList) {
			const auto& key = adj.first;
			const auto& vec = adj.second;
			cout << key->val << ": ";
			view_vector(vec);
		}
	}
};

void view_vector(vector<Vertex *> demo) {
	for (auto& each : demo)
		cout << each->val << " ";
	cout << endl;
}

int main() {
	vector<Vertex*> vertices = valsToVets({ 0, 1, 2, 3, 4 });
	vector<vector<Vertex*>> edges = { {vertices[1], vertices[2]}, {vertices[2], vertices[4]} };

	GraphAdjList graph(edges);
	graph.print(); // Print the adjacency list

	for (Vertex* vet : vertices) {
		delete vet;
	}

	return 0;
}