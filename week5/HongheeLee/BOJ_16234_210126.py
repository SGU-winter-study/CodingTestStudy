'''
    문제설명
        백준 16234 인구이동(BFS 이용)
        인구 차이에 근거해서 국경선을 열고 닫고 국경선을 열 수 없을 때까지 몇번의 인구 변화가 일어나는지 구하기
    해결전략
        BFS를 이용해서 같은 연합을 이루는 국가를 구하고 연합 국가 인구의 평균을 구해서 각 국가의 인구수를 갱신한다.
        연합 국가를 찾을 때는 시작 국가의 좌표에서부터 12, 3, 6, 9시 순서로 탐색하며 좌표가 범위 안에 있는지, 
        인구 차이의 절댓값이 문제에서 주어진 범위 안에 있는지 파악해서 조건에 맞을 때 큐에 추가하고 방문했음을 표시한다. 
        모든 국가를 탐색했는데도 2개 이상의 국가의 연합이 생기는 경우가 없으면 그때 무한루프를 종료하고 그때까지의 인구이동 횟수를 출력한다. 
'''
import sys
from collections import deque
input = sys.stdin.readline
def BFS(i, j):
    Q = deque()
    Q.append((i, j))
    temp = []
    temp.append((i, j))
    while Q:
        x, y = Q.popleft()
        for i in range(4):
            xx = x + dx[i]
            yy = y + dy[i]
            if 0 <= xx < n and 0 <= yy < n and visited[xx][yy] == 0:
                if L <= abs(arr[x][y] - arr[xx][yy]) <= R:
                    visited[xx][yy] = 1
                    Q.append((xx, yy))
                    temp.append((xx, yy))
    return temp

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
n, L, R = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
cnt = 0
while True:
    visited = [[0] * n for _ in range(n)]
    isMoved = False
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0:
                visited[i][j] = 1
                tmp = BFS(i, j)
                if len(tmp) > 1:
                    isMoved = True
                    num = sum([arr[x][y] for x, y in tmp]) // len(tmp)
                    for x, y in tmp:
                        arr[x][y] = num
    if not isMoved:
        break
    cnt += 1
print(cnt)
