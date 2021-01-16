'''
    문제설명
        백준 11724 연결 요소의 개수(DFS 이용)
        무방향 그래프 주어졌을 때 연결 요소의 개수 구하기
    해결전략
        그래프를 표현할 수 있는 방식은 인접행렬과 인접리스트가 있다.
        간선의 수가 많을 때는 인접행렬 방식이 효율적이고 간선의 수에 비해 노드의 수가 많을 때는 인접 리스트가 효율적이다.
        각 노드의 인접리스트를 담은 2차원 리스트와 방문여부를 표시할 리스트를 사용한다.
        입력으로 주어진 간선 정보를 바탕으로 인접리스트를 초기화한다.
        모든 정점을 돌며 아직 방문하지 않은 정점을 시작점으로 삼아 DFS를 수행한다. 
        DFS에서는 시작정점과 연결되어 있는 정점을 모두 방문하고 함수를 종료한다.
        이 과정을 반복하면 결국 DFS를 호출하는 총 횟수가 연결성분의 개수가 된다. 
'''
import sys
sys.setrecursionlimit(10**6)
def DFS(v):
    visited[v] = True
    for x in adj[v]:
        if not visited[x]:
            DFS(x)
n, m = map(int, sys.stdin.readline().split())
adj = [[] for _ in range(n+1)]
visited = [False] * (n+1)
cnt = 0
for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    adj[a].append(b)
    adj[b].append(a)
for i in range(1, n+1):
    if not visited[i]:
        DFS(i)
        cnt += 1
print(cnt)
