'''
    문제설명
        PGM 네트워크 
        그래프의 연결요소의 개수 구하는 문제와 유사하다. 
    해결전략
        BFS(너비우선탐색)으로 해결한다. 주어진 인접행렬과 해당 정점의 방문 여부를 표시하는 visited 리스트를 이용한다.
        visited 리스트를 fot문으로 돌며 방문하지 않은 정점을 시작정점으로 삼아 BFS 탐색을 시작한다. 
            1. 덱에 시작정점을 추가한다.
            2. 덱의 앞에서 한 정점을 꺼내고 그 정점에 연결되어 있으면서 아직 방문하지 않은 정점을 덱에 추가하고 방문했음을 표시한다.
            3. 덱이 빌 때까지 2번을 반복한다.
        BFS 탐색을 마치면 시작정점을 포함하는 연결요소를 하나 찾은 것이므로 연결요소의 개수를 하나 증가시킨다. 
        그 이후에 아직 방문하지 않은 정점이 남아있으면 그 정점을 시작 정점으로 삼아 다시 위의 과정을 반복한다.
        즉, 모든 정점을 방문할 때까지 수행한 BFS 탐색의 횟수가 연결요소의 개수라고 할 수 있다.
'''
from collections import deque
def BFS(v, comps, visited):
    Q = deque()
    Q.append(v)
    while Q:
        tmp = Q.popleft()
        for i in range(len(comps)):
            if comps[tmp][i] == 1 and visited[i] == 0:
                Q.append(i)
                visited[i] = 1
            
def solution(n, computers):
    visited = [0] * n
    cnt = 0
    for i in range(n):
        if visited[i] == 0:
            visited[i] = 1
            BFS(i, computers, visited)
            cnt += 1
    return cnt
