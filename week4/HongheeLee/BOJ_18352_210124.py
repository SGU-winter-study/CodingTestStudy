'''
    문제설명
        백준 18352 특정 거리의 도시 찾기 (BFS 이용)
        특정 도시로부터 출발해여 도달할 수 있는 도시 중 최단거리가 K인 도시 모두 출력하기.
    해결전략
        주어질 수 있는 최대 도시의 수가 30만으로 크기 때문에 인접행렬이 아닌 인접리스트로 그래프를 표현하였다.
        BFS는 deque로 구현했는데 큐에 현재 도시 번호와 거기까지의 최단거리를 튜플로 넣었다. 
        큐에서 하나씩 꺼내며 최단거리가 목표 K와 같아지면 그 도시 번호를 결과 res에 추가했고 
        목표와 다르면 최단거리를 +1 하면서 해당 도시에서 갈 수 있는 다른 도시로 이동시키는 방식으로 BFS 탐색을 계속했다. 
        또한 도시를 방문했을 때는 visited 리스트에 방문했음을 표시해서 중복해서 방문하지 않도록 했다.
'''
import sys
from collections import deque
input = sys.stdin.readline
def BFS(k, x):
    visited[x] = True
    Q = deque()
    Q.append((x, 0))
    while Q:
        city, leng = Q.popleft()
        if leng == k:
            res.append(city)
        for i in adj[city]:
            if not visited[i]:
                Q.append((i, leng+1))
                visited[i] = True
n, m, k, x = map(int, input().split())
adj = [[] for _ in range(n+1)]
visited = [False] * (n+1)
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
res = []
BFS(k, x)
res.sort()
if len(res) == 0:
    print(-1)
else:
    for a in res:
        print(a)
