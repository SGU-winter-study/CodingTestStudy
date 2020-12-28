/* https://programmers.co.kr/learn/courses/30/lessons/68937

BOJ 1967과 유사 기본적으로 bfs 2번으로 가장 먼 노드를 찾는다

이후 최대값이 2개 이상 나오면 최대값이 중앙값 
아니라면 최대값 -1 이 
중앙값 visit 배열을 사용하기 싫어서 distance값에 1을 더해서 사용함 (dist == 0이면 미방문) 
dist 를 -1로 초기화하고 하는 방법이 더 좋은 방법인거 같음 
따라서 결과를 구할 때 -1을 해줘야함 단순 bfs와 아이디어로 해결할 수 있는 문제 
시간복잡도 O(n)으로 풀 수 있음

*/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <random>
using namespace std;

#define all(v) (v).begin(),(v).end()
using pii = pair<int, int>;
using lint = long long;
using pll = pair<lint, lint>;

const int MOD = 1e9 + 7, INF = 987654321;
const lint LMOD = 1e9 + 7;
const lint LINF = 987654321987654321;
const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, -1, 0, 1 };
const double PI = 3.14159265359;
const int mxn = 250000 + 1;

vector<int> adj[mxn];
int dist[mxn];

int bfs(int start) {
	int ret = -1;
	int _max = -1;
	queue<int> q;
	q.push(start);
	fill(dist, dist + mxn, 0);
	dist[start] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto nxt : adj[now]) {
			if (dist[nxt]) continue;

			dist[nxt] = dist[now] + 1;
			q.push(nxt);
			if (dist[nxt] > _max) {
				_max = dist[nxt];
				ret = nxt;
			}
		}
	}

	return ret;
}

int solution(int n, vector<vector<int>> edges) {
	int answer = 0;
	for (int i = 0; i < edges.size(); i++) {
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}
	int nxt = bfs(1);
	nxt = bfs(nxt);
	int _mxn = dist[nxt];
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == _mxn) cnt++;
	}
	if (cnt == 1) {
		nxt = bfs(nxt);
		int ncnt = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] == _mxn) ncnt++;
		}
		if (ncnt == 1)
			answer = dist[nxt] - 2;
		else
			answer = dist[nxt] - 1;
	}
	else
		answer = dist[nxt] - 1;
	return answer;
}