'''
    문제설명
        백준 1753 최단경로 (다익스트라 알고리즘 이용)
        방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단경로 구하기
    해결전략
        한 점에서 다른 모든 정점까지의 최단경로 구하는 문제이므로 다익스트라 알고리즘 이용한다.
        기존에 인접행렬로 그래프를 표현해서 다익스트라 알고리즘를 사용하면 시간복잡도는 O(V^2), 공간복잡도도 O(V^2)이다.
        우선순위 큐를 이용하면 시간복잡도를 줄일 수 있었고 인접리스트 방식을 이용하면 공간복잡도를 줄일 수 있었다. 이를 위해 파이썬의 heapq를 사용했다.
        구체적으로는 우선순위 큐를 사용해서 최단거리에 있는 노드를 선택하고 그 노드와 인접한 노드까지의 거리를 계산한다.
        계산이 끝나고 현재 노드에서 인접한 노드까지의 거리가 최소라면 그 인접한 노드를 우선순위 큐에 추가한다.
'''
import sys
import heapq
input = sys.stdin.readline

def dijkstra(start, graph):
    Q = []
    dis = [INF] * (V + 1)
    dis[start] = 0
    heapq.heappush(Q, (0, start))

    while Q:
        cost, loc = heapq.heappop(Q)
        for l, c in graph[loc]:
            c += cost
            if c < dis[l]:
                dis[l] = c
                heapq.heappush(Q, (c, l))
    return dis[1:]
                
INF = sys.maxsize
V, E = map(int, input().split())
K = int(input())
graph = [[] for _ in range(V+1)]
for _ in range(E):
    fr, to, wei = map(int, input().split())
    graph[fr].append((to, wei))
    
for x in dijkstra(K, graph):
    print(x if x != INF else "INF")
