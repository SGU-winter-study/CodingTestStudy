'''
    문제설명
        백준 1260 DFS와 BFS
        그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과 출력
    해결전략
        주어진 간선의 정보를 기반으로 인접행렬을 작성한다. 
        양방향 그래프이기에 대칭적이고, 정점의 번호가 1번부터 시작하므로 인덱스 번호와 맞춰주기 위해 앞에 0을 추가로 넣는다.
        DFS(깊이우선탐색)은 방문한 정점에 체크하고 출력한 뒤 아직 방문하지 않았지만 연결되어있는 정점으로 이동하는데 한 방향으로 깊이 들어간다. 
        BFS(너비우선탐색)은 큐에서 빼면서 정점을 방문하고 출력한다. 그 정점에 연결되어 있지만 아직 방문하지 않은 정점을 차례로 큐에 추가한다.  
'''
from collections import deque

def DFS(s):
    ch1[s] = 1
    print(s, end=' ')
    for i in range(1, n+1):
        if mat[s][i] == 1 and ch1[i] == 0:
            DFS(i)

def BFS(v):
    Q.append(v)
    ch2[v] = 1
    while Q:
        tmp = Q.popleft()
        print(tmp, end=' ')
        for i in range(1, n+1):
            if ch2[i] == 0 and mat[tmp][i] == 1:
                Q.append(i)
                ch2[i] = 1

n, m, v = map(int, input().split())
mat = [[0] * (n+1) for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    mat[a][b] = mat[b][a] = 1
ch1 = [0] * (n+1)
ch2 = [0] * (n+1)
Q = deque()

DFS(v)
print()
BFS(v)
