#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include"21.graph_AdjTable.cpp"
using namespace std;
vector<Vertex*> graphBFS(GraphAdjList& graph, Vertex* startVet) {
	// 这里的问题是，如何处理不连通图的情况
	// Attention：BFS和DFS都需要先指定开始节点
	vector<Vertex*>res;  // 顶点遍历序列
	unordered_set<Vertex*> visited = { startVet };
	queue<Vertex*>que;
	que.push(startVet);
	while (!que.empty()) {
		Vertex* cur = que.front();
		que.pop();
		res.push_back(cur);
		cout << cur->val << endl;
		vector<Vertex*> cur_related = graph.adjList[cur];
		for (Vertex* each_node : cur_related) {
			if (!visited.count(each_node)) {
				visited.insert(each_node);
				que.push(each_node);
			}
		}
	}
	return res;
}

vector<Vertex*> graphDFS(GraphAdjList& graph, Vertex* startVet) {
	vector<Vertex*> res;
	unordered_set<Vertex*> visited = { startVet };
	dfs(graph, res, visited, startVet);
	return res;
}
void dfs(GraphAdjList& graph, vector<Vertex*>& res, unordered_set<Vertex*>& visited, Vertex* cur_vet) {
	if (visited.count(cur_vet) != 0) {
		return;
	}
	res.push_back(cur_vet);
	visited.insert(cur_vet);
	for (auto& each_vet : graph.adjList[cur_vet]) {
		if (visited.count(each_vet) == 0)
			dfs(graph, res, visited, each_vet);
		else
			continue;
	}
}


// int main() {
// 	vector<Vertex*> v = valsToVets({ 0, 1, 2, 3, 4, });
// 	vector<vector<Vertex*>> edges = { {v[0], v[1]}, {v[0], v[3]}, {v[1],v[0]},{v[2],v[4]} };
// 	//vector<vector<Vertex*>> edges = { {vertices[1], vertices[2]}, {vertices[2], vertices[4]} };

// 	GraphAdjList graph(edges);
// 	graph.print(); // Print the adjacency list

// 	for (Vertex* vet : v) {
// 		delete vet;
// 	}
// 	graphBFS(graph, new Vertex(1));
// 	return 0;
// }