'''
    문제설명
        백준 1916 최소비용 구하기(다익스트라 알고리즘 이용)
        A 도시에서 B 도시로 가는데 드는 최소 비용을 출력한다
    해결전략
        다익스트라 알고리즘을 이용해서 한 정점으로부터 다른 모든 정점으로의 최소 비용(거리)를 구한다.
        현재 정점에서 가장 가까운 정점을 빠르게 찾기 위해 우선순위 큐를 이용해서 다익스트라 알고리즘을 구현한다.  
        그래프에 대해 주어진 입력(시작 정점, 도착 정점, 가중치)를 인접 리스트 형태로 저장한다.
        우선순위 큐에 출발 정점을 넣고 하나씩 꺼내면서 꺼낸 정점을 거쳐서 갔을 때의 거리가 더 짧으면 
        출발 정점으로부터 각 정점까지의 최단 거리인 dis 리스트를 갱신한다.
'''
import sys
import heapq
input = sys.stdin.readline

def dij(graph, start, end):
    Q = []
    dis = [INF] * (n+1)
    dis[start] = 0
    heapq.heappush(Q, (0, start))
    while Q:
        cost, pos = heapq.heappop(Q)
        for to, wei in graph[pos]:
            wei += cost
            if wei < dis[to]:
                dis[to] = wei
                heapq.heappush(Q, (wei, to))
    return dis[end]

INF = sys.maxsize
n = int(input())
m = int(input())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    fr, to, wei = map(int, input().split())
    graph[fr].append((to, wei))
start, end = map(int, input().split())
print(dij(graph, start, end))
