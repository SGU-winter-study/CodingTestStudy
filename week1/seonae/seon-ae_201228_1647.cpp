#include <iostream>
#include <vector>
#include <algorithm>

#define max_n 100001
using namespace std;
int parent[max_n];
int n, m; 

struct Edge {
	int a, b, c;
	Edge(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};
bool comparator(Edge& a, Edge& b) {
	return a.c < b.c;
}
vector<Edge> edgeList;

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else return parent[a] = find(parent[a]);
}

void union_func(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);
	if (rootA < rootB) {
		parent[rootB] = rootA;
	}
	else parent[rootA] = rootB;
}

int main() {
	cin >> n >> m;
	// initial graph
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edgeList.push_back(Edge(from, to, cost));
	}
	// kruskal algorithm 
	// 1. sort by costs between edges
	// 2. if the edge doesn't make cycle, union 
	sort(edgeList.begin(), edgeList.end(), comparator);

	for (int i = 0; i < max_n; i++) {
		parent[i] = i;
	}
	int answer = 0;
	int edges_cnt = 0;
	for (int i = 0; i < m; i++) {
		Edge edge = edgeList[i];
		int a = edge.a;
		int b = edge.b;
		int c = edge.c;
		if (find(a) != find(b)) {
			union_func(a, b);
			answer += c;
			edges_cnt++;
		}
		// spanning tree : (# of edges)= (# of vertex-1)
		if (edges_cnt == n - 1) {
			// 마지막에 더해준 cost 값을 빼주면 그게 곧 마을 분리
			answer -= c;
			break;
		}
	}

	cout << answer;
}


