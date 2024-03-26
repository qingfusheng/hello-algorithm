// 题目名称：2642. 设计可以求最短路径的图类
// 题目来源：LeetCode
// 题目难度：困难
// 题目链接：https://leetcode.cn/problems/design-graph-with-shortest-path-calculator/description
// 题目思路：有向图，单源两点最短路径，Dijistra算法，邻接表，邻接矩阵，Floyd算法
// 备注：磨了很久，也可以算是Dijistra的模板题，本来是想用动规做的（也就是所谓的FloydWarshall算法），不过超时严重。

#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

class Graph {
private:
public:
    Graph(int numNodes, vector<vector<int>> edges) {
    }

    void addEdge(vector<int> edge) {
    }
    int shortestPath(int node1, int node2) {
        return 0;
    }
};

int main() {
    vector<int> height{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int result;
    int n = 4;
    vector<vector<int>> edges{ {0, 2, 5}, { 0, 1, 2 }, { 1, 2, 1 }, { 3, 0, 3 } };
    Graph* graph = new Graph(n, edges);
    result = graph->shortestPath(3, 2);
    cout << "result1:" << result << endl;
    result = graph->shortestPath(0, 3);
    cout << "result2:" << result << endl;
    vector<int> add_edges{ 1, 3, 4 };
    graph->addEdge(add_edges);
    result = graph->shortestPath(0, 3);
    cout << "result3:" << result << endl;
    delete graph;
    return 0;
}


/*
//单源两点最短路径，邻接表，Dijistra算法

#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

class Graph {
private:
    int n;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int numNodes, vector<vector<int>> edges) {
        n = numNodes;
        adjList.resize(n);
        for (auto edge : edges) {
            adjList[edge[0]].push_back({ edge[1], edge[2] });
        }
    }

    void addEdge(vector<int> edge) {
        adjList[edge[0]].push_back({ edge[1], edge[2] });
    }

    int shortestPath(int start, int end) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({ 0, start });

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto neighbor : adjList[u]) {
                int v = neighbor.first;  // 节点
                int w = neighbor.second;  // weight权重
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({ dist[v], v });
                }
            }
        }
        return dist[end] == INT_MAX ? -1 : dist[end];
    }
};
*/

/*
* // 单源两点最短路径，邻接矩阵，Dijistra算法，时间↑，空间↓
class Graph {
private:
    int n;
    vector<vector<int>> adjMatrix;

public:
    Graph(int numNodes, vector<vector<int>> edges) {
        n = numNodes;
        adjMatrix.resize(n, vector<int>(n, INT_MAX));
        for (auto edge : edges) {
            adjMatrix[edge[0]][edge[1]] = edge[2];
        }
    }

    void addEdge(vector<int> edge) {
        adjMatrix[edge[0]][edge[1]] = edge[2];
    }

    int shortestPath(int start, int end) {
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[start] = 0;

        for (int count = 0; count < n - 1; ++count) {
            int u = -1;
            for (int i = 0; i < n; ++i) {
                if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }

            visited[u] = true;

            for (int v = 0; v < n; ++v) {
                if (!visited[v] && adjMatrix[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        return dist[end] == INT_MAX ? -1 : dist[end];
    }
};
*/

/*
* // 邻接矩阵，但是Floyd，初始化和每次AddEdge都会对dist进行更新，超时超内存严重，但是如果不那么频繁更新dist的话我感觉应该还好。
* // 可以计算多源最短路径。
class Graph {
private:
    int n;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> dist;
public:
    Graph(int numNodes, vector<vector<int>> edges) {
        n = numNodes;
        adjMatrix.resize(n, vector<int>(n, INT_MAX));
        for (auto edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            adjMatrix[from][to] = weight;
        }
        this->floydWarshall();
    }

    void addEdge(vector<int> edge) {
        int from = edge[0];
        int to = edge[1];
        int weight = edge[2];
        adjMatrix[from][to] = weight;
        this->floydWarshall();  // 添加edge后需要重新对dist数组进行更新
    }

    void floydWarshall() {
        dist = vector<vector<int>>(adjMatrix);
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        // 虽然但是，有一个demo是[11,11]
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;
    }
    int shortestPath(int node1, int node2) {
        return this->dist[node1][node2] == INT_MAX ? -1: this->dist[node1][node2];
    }
};
*/